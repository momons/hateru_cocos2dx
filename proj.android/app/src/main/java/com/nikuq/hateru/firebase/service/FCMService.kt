package com.nikuq.hateru.firebase.service

import android.util.Log
import com.google.firebase.messaging.FirebaseMessagingService
import com.google.firebase.messaging.RemoteMessage

/**
 * FCMサービス
 */
class FCMService: FirebaseMessagingService() {

    companion object {
        /** タグ */
        private val TAG = FirebaseMessagingService::class.java.simpleName
    }

    /**
     * トークン取得
     */
    override fun onNewToken(token: String?) {
        super.onNewToken(token)
        Log.d(TAG, "Refreshed token: $token")
    }

    /**
     * メッセージ受信
     */
    override fun onMessageReceived(message: RemoteMessage?) {
        super.onMessageReceived(message)


    }
}