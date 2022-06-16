#
#  Be sure to run `pod spec lint YXTLogger.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "YXTLogger"
  spec.version      = "1.0.13"
  spec.summary      = "yxt logger plugin"

  spec.description  = <<-DESC
  YXTLogger is a log plug-in that records at different levels and uploads at different levels. It relies on CocoaLumberjack to implement it internally. 
                   DESC

  spec.homepage     = "https://www.plaso.cn"

  spec.license      = { :type => 'Copyright', :text => <<-LICENSE
    Copyright 2018 plaso.cn. All rights reserved.
  LICENSE
    }

  spec.author             = { "luyi" => "yi.lu@plaso.cn" }


  spec.platform     = :ios, "9.0"

  spec.source       = { :http => "https://wwwr.plaso.cn/static/sdk/ios/#{spec.name}/#{spec.version}/#{spec.name}.zip" }


  spec.ios.vendored_frameworks  = "#{spec.name}.framework"


  spec.requires_arc = true
  
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
  spec.dependency 'CocoaLumberjack', '~> 3.5.3'

end
