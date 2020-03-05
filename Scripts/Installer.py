
#  installer.py
#  Simple Python3 installer for packages
#  Made by Litchyx Team
#  Created on 6/03/2020


import os
import platform

class Setup():

    def __init__(self):
        
        print('+------------------------------------------------------+')
        print('|           Package Installer - v1.0.0 alpha           |')
        print('|                 Made By Litchyx Team                 |')
        print('+------------------------------------------------------+')
        print("| Operating System : " + platform.system())
        print("| Release          : " + platform.release())
        print("| Installer Version  : v1.0 alpha                    []|")


    def setup(self):
        """ Setup

        This method will find the OS install route and then perform the installation
        for that specific OS
        """

        # Check the platform and perform install for that platform
        if platform.system() == "Darwin":
            print('| MacOS Install Route                            []|')
            self.mac_osx_install_route()
        elif platform.system() == "Linux":
            print('| Linux Install Route                            []|')
            self.linux_install_route()
        elif platform.system() == "Windows":
            print('| Windows Install Route                          []|')
        else:
            print('| Default Install Route                          []|')
            
        print("+------------------------------------------------------+")


    def mac_osx_install_route(self):


        # CHOMD +X Changes the permissions of the fle to make it executable
        os.system("chmod +x ./src/main.py")
        print("| Set Package Installer Executable Permission           []|")

        # Add customised directory to the $PATH
        os.system('export PATH="$PATH:$HOME/bin"')
        print("| Add Customised Directory to $PATH                     []|")

        # Create a symbolic link to the script
        os.system("ln -s " + os.getcwd() + "/src/main.py /usr/local/bin/LunaLynx")
        print("| Create Symbolic Link to Script                        []|")
        #print(os.getcwd() + "/src/main.py")
        
   def linux_install_route(self):
    
        #linux code


if __name__ == "__main__":
    installer = Setup()
    installer.setup()

    
