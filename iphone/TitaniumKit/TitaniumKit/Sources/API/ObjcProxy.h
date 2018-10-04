/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2018-Present by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
#import <JavaScriptCore/JavaScriptCore.h>
#import <pthread.h>

@protocol ProxyExports <JSExport>

@property (readonly, nonatomic) NSString *apiName;
/**
 Indicates that this proxy should honor bubbling of user events, if the proxy
 is the type that has a parent to bubble to (This is primairly views, but may
 have some exceptions).
 */
@property (readwrite, assign) BOOL bubbleParent;

JSExportAs(addEventListener,
           -(void)addEventListener
           : (NSString *)name withCallback
           : (JSValue *)callback);
JSExportAs(removeEventListener,
           -(void)removeEventListener
           : (NSString *)name withCallback
           : (JSValue *)callback);
JSExportAs(fireEvent,
           -(void)fireEvent
           : (NSString *)name withDict
           : (NSDictionary *)dict);

@end

/**
 The base class for Titanium proxies using new Obj-C API.
 */
@interface ObjcProxy : NSObject <ProxyExports> {
  @private
  NSMutableDictionary *m_listeners; // new listener map for Obj-C JSC API
  pthread_rwlock_t m_listenerLock;
  NSURL *baseURL;
}

- (NSURL *)_baseURL;
@end
