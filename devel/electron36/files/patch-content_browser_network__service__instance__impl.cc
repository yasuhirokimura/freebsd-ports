--- content/browser/network_service_instance_impl.cc.orig	2025-04-22 20:15:27 UTC
+++ content/browser/network_service_instance_impl.cc
@@ -83,7 +83,7 @@
 #include "content/browser/network/network_service_process_tracker_win.h"
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/browser/system_dns_resolution/system_dns_resolver.h"
 #include "services/network/public/mojom/system_dns_resolution.mojom-forward.h"
 #endif
@@ -341,7 +341,7 @@ void CreateInProcessNetworkService(
                                 std::move(receiver)));
 }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Runs a self-owned SystemDnsResolverMojoImpl. This is meant to run on a
 // high-priority thread pool.
 void RunSystemDnsResolverOnThreadPool(
@@ -410,7 +410,7 @@ network::mojom::NetworkServiceParamsPtr CreateNetworkS
   }
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (GetContentClient()
           ->browser()
           ->ShouldRunOutOfProcessSystemDnsResolution() &&
