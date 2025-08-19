#
#  Be sure to run `pod spec lint TiCloud-RTC-iOS.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#


Pod::Spec.new do |s|
  s.name         = "TiCloudRTCOutCallUI"
  s.version      = "1.0.0.001"
  s.summary      = "TiCloudRTC iOS实时语音呼叫SDK带呼叫UI"

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/ti-net/TiCloud-RTC-iOS.git'
  s.license          = { :type => 'MIT'}
  s.author           = { 'zhupeng' => 'zhupeng@live800.com' }
  s.source           = { :git => 'https://github.com/ti-net/TiCloud-RTC-iOS.git', :branch => 'OutCallUI', :tag => s.version.to_s }

  s.ios.deployment_target = '12.0'

  s.vendored_frameworks  = "TiCloudRTCOutCallUI.framework"
  s.pod_target_xcconfig = {'VALID_ARCHS'=>'arm64 x86_64','EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  s.dependency 'TiCloudRTC', '4.2.21.25081801'


end
