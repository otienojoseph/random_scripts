#!/bin/sh
echo -----------------------------------------
echo Hello from android
echo -----------------------------------------
if (adb devices); then
	echo Getting state
	adb get-state
fi
