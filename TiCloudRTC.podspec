#
#  Be sure to run `pod spec lint TiCloud-RTC-iOS.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#


Pod::Spec.new do |s|
  s.name         = "TiCloudRTC"
  s.version      = "4.2.19"
  s.summary      = "TiCloudRTC iOS实时语音呼叫SDK"

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/ti-net/TiCloud-RTC-iOS.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'gyb1314' => 'gyb_1314@126.com' }
  s.source           = { :git => 'https://github.com/ti-net/TiCloud-RTC-iOS.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'

  s.vendored_frameworks  = "TiCloudRTC.framework",  "AgoraRtmKit.xcframework"
  s.resource      = 'TiCloudRTCBundle.bundle'
  s.pod_target_xcconfig = {'VALID_ARCHS'=>'arm64 x86_64','EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  #s.dependency 'AgoraRtm_iOS', '1.5.1'
  s.dependency 'AgoraRtcEngine_iOS', '4.3.2'


end