--- src/3rdparty/chromium/content/common/features.h.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/content/common/features.h
@@ -34,7 +34,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kDocumentPolicyNeg
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableBackForwardCacheForScreenReader);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(
     kEnableBackForwardCacheForOngoingSubframeNavigation);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableDevToolsJsErrorReporting);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEmbeddingRequiresOptIn);
@@ -76,7 +76,7 @@ CONTENT_EXPORT extern const base::FeatureParam<int>
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kGpuInfoCollectionSeparatePrefetch);
 #endif
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kGroupNIKByJoiningOrigin);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kHandleChildThreadTypeChangesInBrowser);
 #endif
 #if BUILDFLAG(IS_ANDROID)
