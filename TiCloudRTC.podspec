Pod::Spec.new do |s|
  s.name         = "TiCloudRTC"
  s.version      = "3.10.6"
  s.summary      = "TiCloudRTC iOS实时语音呼叫SDK"

  s.description      = <<-DESC
TiCloudRTC 是一个基于 Agora RTC/RTM 的 iOS 实时语音呼叫 SDK，
封装了呼叫状态管理、信令协同和音频通话能力。
当前发布产物为真机 arm64 二进制 framework，不包含 iOS Simulator slice。
  DESC

  s.homepage         = "https://github.com/ti-net/TiCloud-RTC-iOS"
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'gyb1314' => 'gyb_1314@126.com' }
  s.source           = { :git => 'https://github.com/ti-net/TiCloud-RTC-iOS.git', :tag => s.version.to_s  }

  s.platform         = :ios, "12.0"

  s.vendored_frameworks = "TiCloudRTC.framework"

  s.dependency 'AgoraRtm_iOS', '1.5.1'
  s.dependency 'AgoraRtcEngine_iOS', '4.3.2'
end
