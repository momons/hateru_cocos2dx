package com.nikuq.hateru.firebase.auth

import android.app.Activity
import android.content.Intent
import android.util.Log
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.TwitterAuthProvider
import com.nikuq.hateru.BuildConfig
import com.nikuq.hateru.R
import com.twitter.sdk.android.core.*
import com.twitter.sdk.android.core.identity.TwitterAuthClient

/** Twitter認証 */
class TwitterAuth(val activity: Activity) {

    companion object {
        init {
            System.loadLibrary("MyGame")
        }

        /** タグ */
        private val TAG = GoogleAuth::class.java.simpleName
    }

    init {
        val authConfig = TwitterAuthConfig(
                activity.getString(R.string.consumer_api_key),
                activity.getString(R.string.consumer_api_secret_key))
        val config = TwitterConfig.Builder(activity)
                .logger(DefaultLogger(Log.DEBUG))
                .twitterAuthConfig(authConfig)
                .debug(BuildConfig.DEBUG)
                .build()
        Twitter.initialize(config)
    }

    /** サインイン完了ハンドラ true:成功、false:失敗 */
    var handler: ((Boolean) -> Unit)? = null

    /** 認証クライアント */
    private val authClient = TwitterAuthClient()

    /**
     * Twitterログイン
     */
    fun login() {
        authClient.authorize(activity, object: Callback<TwitterSession>() {

            override fun success(result: Result<TwitterSession>) {
                firebaseLogin(result.data.authToken.token, result.data.authToken.secret)
            }

            override fun failure(exception: TwitterException) {
                Log.w(TAG, "failed twitter sign in. " + exception.localizedMessage)
                handler?.let { it(false) }
                onCompletion(false)
            }
        })
    }

    /**
     * Activityの終了イベントをハンドルする
     *
     * @param requestCode リクエストコード
     * @param resultCode  完了コード
     * @param data        データ
     */
    fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent) {
        authClient.onActivityResult(requestCode, resultCode, data)
    }

    /**
     * もらったIDトークンよりTwitter認証する
     *
     * @param token  トークン
     * @param secret シークレット
     */
    private fun firebaseLogin(token: String, secret: String) {
        val credential = TwitterAuthProvider.getCredential(token, secret)
        FirebaseAuth.getInstance().signInWithCredential(credential)
                .addOnCompleteListener(activity) { task ->
                    if (!task.isSuccessful) {
                        Log.w(TAG, "twitter sign in. " + task.isSuccessful)
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