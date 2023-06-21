﻿import os
import subprocess
import platform

from SetupPython import PythonConfiguration as PythonRequirements
PythonRequirements.Validate()

from SetupVulkan import VulkanConfiguration as VulkanRequirements
os.chdir('./../')
VulkanRequirements.Validate()

print("\nUpdating submodules...")
subprocess.call(["git", "submodule", "update", "--init", "--recursive"])

from SetupPremake import PremakeConfiguration as PremakeRequirements
premakeInstalled = PremakeRequirements.Validate()

if premakeInstalled:
    if platform.system() == "Windows":
        print("\nGenerating ORigin.sln...")
        origin_sln = os.path.abspath("./Scripts/premake5.bat")
        subprocess.call([origin_sln, "nopause"])
        
        print("\nGenerating ORiginSandbox.sln...")
        originSandbox_sln = os.path.abspath("./ORigin-Editor/SandboxProject/WinGen.bat")
        subprocess.call([originSandbox_sln, "nopause"])

    print("Setup Completed!")
else:
    print("ORigin requires Premake to generate project file.")