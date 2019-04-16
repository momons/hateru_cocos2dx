package com.nikuq.hateru.firebase.auth

import android.app.Activity

/** Twitter認証 */
class TwitterAuth(val activity: Activity) {

    companion object {
        init {
            System.loadLibrary("MyGame")
        }
    }

    /** サインイン完了ハンドラ true:成功、false:失敗 */
    var handler: ((Boolean) -> Unit)? = null

    /**
     * Twitterログイン
     */
    fun login() {

    }

    /**
     * 終了をC++側にコールバックする
     *
     * @param token true:成功、false:失敗
     */
    external fun onCompletion(success: Boolean)
}