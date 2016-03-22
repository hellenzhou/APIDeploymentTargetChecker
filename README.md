# APIDeploymentTargetChecker

## Deprecated from Xcode 7.3 which supports -Wpartial-availability flag

Be warn about iOS API call not available for current deployment target at compile time


### Warning : this is a Hack that modify a header within Xcode SDKs

Use deployPatch.sh to patch CFAvailability.h file in iPhoneOS and iPhoneSimulator SDKs

Add -imacros MJGAvailability.h to your OTHER_CLAFGS

This will allow you to get some nice compile time errors like :

![Error using a too new API](/error_api_too_new.png "Error using a too new API")
