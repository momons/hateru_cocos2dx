package com.nikuq.hateru.firebase.service

import android.util.Log
import com.google.firebase.messaging.FirebaseMessagingService
import com.google.firebase.messaging.RemoteMessage

/**
 * FCMサービス
 */
class FCMService: FirebaseMessagingService() {

    companion object {
        init {
            System.loadLibrary("MyGame")
        }

        /** タグ */
        private val TAG = FirebaseMessagingService::class.java.simpleName
    }

    /**
     * トークン取得
     */
    override fun onNewToken(token: String?) {
        super.onNewToken(token)
        Log.d(TAG, "Refreshed token: $token")
        // トークン保存
        token?.let { writeToken(it) }
    }

    /**
     * メッセージ受信
     */
    override fun onMessageReceived(message: RemoteMessage?) {
        super.onMessageReceived(message)
    }

    /**
     * トークンを保存する
     *
     * @param token トークン
     */
    external fun writeToken(token: String)
}