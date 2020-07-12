/*
 * (C) Copyright 2013 Kurento (http://kurento.org/)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* inclusion guard */
#ifndef __KMS_HTTP_EP_SERVER_H__
#define __KMS_HTTP_EP_SERVER_H__

#include <gst/gst.h>
#include <glib-object.h>

#include "kmshttpendpointaction.h"

/*
 * Type macros.
 */
#define KMS_TYPE_HTTP_EP_SERVER (            \
  kms_http_ep_server_get_type ()             \
)

#define KMS_HTTP_EP_SERVER(obj) (            \
  G_TYPE_CHECK_INSTANCE_CAST (               \
    (obj),                                   \
    KMS_TYPE_HTTP_EP_SERVER,                 \
    KmsHttpEPServer                          \
  )                                          \
)

#define KMS_IS_HTTP_EP_SERVER(obj) (         \
  G_TYPE_CHECK_INSTANCE_TYPE (               \
    (obj),                                   \
    KMS_TYPE_HTTP_EP_SERVER                  \
  )                                          \
)

#define KMS_HTTP_EP_SERVER_CLASS(klass) (    \
  G_TYPE_CHECK_CLASS_CAST (                  \
    (klass),                                 \
    KMS_TYPE_HTTP_EP_SERVER,                 \
    KmsHttpEPServerClass                     \
  )                                          \
)

#define KMS_IS_HTTP_EP_SERVER_CLASS(klass) ( \
  G_TYPE_CHECK_CLASS_TYPE (                  \
    (klass),                                 \
    KMS_TYPE_HTTP_EP_SERVER                  \
  )                                          \
)

#define KMS_HTTP_EP_SERVER_GET_CLASS(obj) (  \
  G_TYPE_INSTANCE_GET_CLASS (                \
    (obj),                                   \
    KMS_TYPE_HTTP_EP_SERVER,                 \
    KmsHttpEPServerClass)                    \
)

#define KMS_HTTP_EP_SERVER_ERROR \
  g_quark_from_static_string("kms-http-ep-server-error-quark")

typedef enum
{
  HTTPEPSERVER_RESOLVE_CANCELED_ERROR,
  HTTPEPSERVER_CANT_RESOLVE_ERROR,
  HTTPEPSERVER_UNEXPECTED_ERROR
} HttpEPServerError;

typedef struct _KmsHttpEPServer KmsHttpEPServer;
typedef struct _KmsHttpEPServerClass KmsHttpEPServerClass;
typedef struct _KmsHttpEPServerPrivate KmsHttpEPServerPrivate;

typedef void (*KmsHttpEPServerNotifyCallback) (KmsHttpEPServer * self,
    GError * err, gpointer user_data);
typedef void (*KmsHttpEPRegisterCallback) (KmsHttpEPServer * self,
    const gchar *uri, GstElement *e, GError * err, gpointer data);

struct _KmsHttpEPServer
{
  GObject parent_instance;

  /* instance members */

  /*< private > */
  KmsHttpEPServerPrivate *priv;
};

struct _KmsHttpEPServerClass
{
  GObjectClass parent_class;

  /* public virtual methods */
  void (*start) (KmsHttpEPServer * self, KmsHttpEPServerNotifyCallback cb,
    gpointer user_data, GDestroyNotify notify);
  void (*stop) (KmsHttpEPServer * self, KmsHttpEPServerNotifyCallback cb,
    gpointer user_data, GDestroyNotify notify);
  void (*register_end_point) (KmsHttpEPServer * self,
    GstElement * endpoint, guint timeout, KmsHttpEPRegisterCallback cb,
    gpointer user_data, GDestroyNotify notify);
  void (*unregister_end_point) (KmsHttpEPServer * self, const gchar *,
    KmsHttpEPServerNotifyCallback cb, gpointer user_data, GDestroyNotify notif);

  /* signal callbacks */
  void (*action_requested) (KmsHttpEPServer * self, gchar * url,
      KmsHttpEndPointAction action);
  void (*url_removed) (KmsHttpEPServer * self, gchar * url);
  void (*url_expired) (KmsHttpEPServer * self, gchar * url);
};

/* used by KMS_TYPE_HTTP_EP_SERVER */
GType kms_http_ep_server_get_type (void);

/* Virtual public methods */
KmsHttpEPServer *kms_http_ep_server_new (const char *optname1, ...);
void kms_http_ep_server_start (KmsHttpEPServer * self,
    KmsHttpEPServerNotifyCallback start_cb, gpointer user_data,
    GDestroyNotify notify);
void kms_http_ep_server_stop (KmsHttpEPServer * self,
    KmsHttpEPServerNotifyCallback stop_cb, gpointer user_data,
    GDestroyNotify notify);
void kms_http_ep_server_register_end_point (KmsHttpEPServer * self,
    GstElement * endpoint, guint timeout, KmsHttpEPRegisterCallback cb,
    gpointer user_data, GDestroyNotify notify);
void kms_http_ep_server_unregister_end_point (KmsHttpEPServer * self,
    const gchar * uri, KmsHttpEPServerNotifyCallback cb, gpointer user_data,
    GDestroyNotify notify);

#define KMS_HTTP_EP_SERVER_PORT "port"
#define KMS_HTTP_EP_SERVER_INTERFACE "interface"
#define KMS_HTTP_EP_SERVER_ANNOUNCED_IP "announced-address"

#endif /* __KMS_HTTP_EP_SERVER_H__ */
