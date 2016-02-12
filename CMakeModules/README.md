Think of this as an override directory.

Blurrr SDK contains a set of CMake files which your project leverages to build.
However, sometimes you may find it desirable or necessary to override the 
default behavior.

If you match the BLurrr SDK's layout of CMakeModules and have your own copy of 
the specific file you want to override here, the Blurrr build process will 
choose your copy before the SDK version.


Example files you may want to override:

Blurrr-OSX-Template-Info.plist.in
Blurrr-OSX-Template.entitlements.in
Blurrr-iOS-Template-Info.plist.in
AndroidGradle/app/src/main/AndroidManifest.xml.in


Look in BlurrrSDK/bootstrap/SharedCMake for the Blurrr SDK files.


For the best results, you should purge and generate the project when you add
an override. Depending on the type of change, you may or may not see the effect
of the change unless you do a purge and generate.



Remember that if you override a file, you will opt-out of any changes made to
the files in the SDK. When you upgrade the SDK, you may want to diff any files
you have overridden and incorporate the changes as reasonable.



Also, you may want to inspect the following files in your project root on 
SDK updates as these files are yours alone. We will try very hard to not make 
changes to these files, but sometimes it needs to happen. Create a new project 
and compare.

CMakeBlurrrDefaultOptionsOverride.cmake
CMakeBlurrrUserFiles.cmake
CMakeBlurrrProjectSettings.cmake
CMakeLists.txt


