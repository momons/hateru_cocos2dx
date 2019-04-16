package com.nikuq.hateru.firebase.auth

import android.app.Activity
import android.content.Intent
import android.util.Log
import com.google.android.gms.auth.api.signin.GoogleSignIn
import com.google.android.gms.auth.api.signin.GoogleSignInClient
import com.google.android.gms.auth.api.signin.GoogleSignInOptions
import com.google.android.gms.common.api.ApiException
import com.google.firebase.auth.FacebookAuthProvider
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.GoogleAuthProvider

import com.nikuq.hateru.R

/** Google認証 */
class GoogleAuth(val activity: Activity) {

    companion object {
        init {
            System.loadLibrary("MyGame")
        }

        /** タグ */
        private val TAG = GoogleAuth::class.java.simpleName

        /** Activityリクエストコード */
        private const val REQUEST_CODE = 10000
    }

    /** 認証クライアント */
    private var client: GoogleSignInClient

    init {
        val gso = GoogleSignInOptions.Builder(GoogleSignInOptions.DEFAULT_SIGN_IN)
                .requestIdToken(activity.getString(R.string.default_web_client_id))
                .requestEmail()
                .build()
        client = GoogleSignIn.getClient(activity, gso)
    }

    /** サインイン完了ハンドラ true:成功、false:失敗 */
    var handler: ((Boolean) -> Unit)? = null

    /**
     * Googleサインイン
     */
    fun signIn() {
        val signInIntent = client.getSignInIntent()
        activity.startActivityForResult(signInIntent, REQUEST_CODE)
    }

    /**
     * Activityの終了イベントをハンドルする
     *
     * @param requestCode リクエストコード
     * @param resultCode  完了コード
     * @param data        データ
     */
    fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent): Boolean {
        if (requestCode != REQUEST_CODE) {
            return false
        }
        val task = GoogleSignIn.getSignedInAccountFromIntent(data)
        try {
            val account = task.getResult(ApiException::class.java)
            account?.let {
                val idToken = account.idToken
                idToken?.let {
                    firebaseLogin(idToken)
                    return true
                }
            }
            Log.w(TAG, "failed google sign in. idToken is null.")
            handler?.let { it(false) }
            onCompletion(false)
        } catch (e: ApiException) {
            Log.w(TAG, "failed google sign in. " + e.localizedMessage)
            handler?.let { it(false) }
            onCompletion(false)
        }
        return true
    }

    /**
     * もらったIDトークンよりGoogle認証する
     *
     * @param idToken IDトークン
     */
    private fun firebaseLogin(idToken: String) {
        val credential = GoogleAuthProvider.getCredential(idToken, null)
        FirebaseAuth.getInstance().signInWithCredential(credential)
                .addOnCompleteListener(activity) { task ->
                    if (!task.isSuccessful) {
                        Log.w(TAG, "google sign in. " + task.isSuccessful)
                    }
                    handler?.let { it(task.isSuccessful) }
                    onCompletion(task.isSuccessful)
                }
    }

    /**
     * 終了をC++側にコールバックする
     *
     * @param token true:成功、false:失敗
     */
    external fun onCompletion(success: Boolean)
}