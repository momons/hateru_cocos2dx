package com.nikuq.hateru.firebase.auth;

import android.app.Activity
import com.facebook.CallbackManager
import com.facebook.FacebookCallback
import com.facebook.FacebookException
import com.facebook.login.LoginManager
import com.facebook.login.LoginResult
import com.google.firebase.auth.FacebookAuthProvider
import com.google.firebase.auth.FirebaseAuth


/** Facebook認証 */
class FacebookAuth(val activity: Activity) {

    companion object {
        init {
            System.loadLibrary("MyGame")
        }
    }

    /** ログイン完了ハンドラ true:成功、false:失敗 */
    var handler: ((Boolean) -> Unit)? = null

    /** Facebookログインコールバックマネージャ */
    val callbackManager = CallbackManager.Factory.create()

    /**
     * Facebookログイン
     */
    fun login() {
        val manager = LoginManager.getInstance()
        manager.registerCallback(callbackManager, object: FacebookCallback<LoginResult> {
            override fun onSuccess(loginResult: LoginResult) {
                firebaseLogin(loginResult.accessToken.token)
            }

            override fun onCancel() {
                handler?.let { it(false) }
                onCompletion(false)
            }

            override fun onError(error: FacebookException?) {
                handler?.let { it(false) }
                onCompletion(false)
            }
        })
        manager.logInWithReadPermissions(activity, arrayListOf("public_profile", "email"))
    }

    /**
     * もらったトークンよりFirebase認証する
     *
     * @param token Facebook認証トークン
     */
    private fun firebaseLogin(token: String) {
        val credential = FacebookAuthProvider.getCredential(token)
        FirebaseAuth.getInstance().signInWithCredential(credential)
                .addOnCompleteListener(activity) { task ->
                    handler?.let {
                        it(task.isSuccessful)
                    }
                    onCompletion(true)
                }
    }

    /**
     * 終了をC++側にコールバックする
     *
     * @param token true:成功、false:失敗
     */
    external fun onCompletion(success: Boolean)
}
