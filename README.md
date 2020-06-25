# fastsnipe-gui

# running
[download the latest release](https://github.com/fastsnipe/gui/releases/latest) and extract to to the same folder as [https://github.com/fastsnipe/fastsnipe/releases/latest](fastsnipe.exe)

# getting your token
Run this in your developer console on https://www.minecraft.net/en-us/profile after logging into minecraft.net
```js
(a=>{if(navigator&&navigator.clipboard)return navigator.clipboard.writeText(a)})(prompt('Here is your token for fastsnipe',document.cookie.split(';').find(b=>b.includes('bearer_token=')).split('=')[1]))
```

# building
Build static libcurl for vc19

Build fastsnipe-gui in Release/x64 with vc142 build tools and Qt 5.15
