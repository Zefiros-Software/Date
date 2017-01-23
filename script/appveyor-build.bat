cd test/
zpm install-package --allow-install --allow-module  || exit /b 1
zpm vs2015 --allow-install || exit /b 1

msbuild Date.sln /property:Configuration=Test /property:Platform=Win32 || exit /b 1

.\bin\Test\Date.exe || exit /b 1