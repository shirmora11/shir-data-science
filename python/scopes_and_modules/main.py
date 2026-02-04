import sys
import modules as m
import os
import getpass
import platform
import stat

def global_var_check(var):
    """function that checks if the variable is a global variable"""
    if var in globals():
        print(f'{var} is a global var')
        return True
    else:
        print(f"'{var}' is not a global variable.")
        return False

def print_path():
    """function that prints the OS the computer is on , the user currently active and the current working directory"""
    plat = sys.platform
    if plat == "win32":
        print("running on windows")
    elif plat == "darwin":
        print("running on macos")
    print(getpass.getuser(),"\n",os.getcwd())

def reverse_command_arg():
    """function that receive a command line argument and gives it back reversed"""
    args_only = sys.argv[1:]
    reverse = args_only[::-1]
    print(reverse)


def exe_check():
    """function that takes a file name from the command line ,search it in the system , checks its executable permissions and if its missing then change it to for the owner"""
    args_only = sys.argv[1:]
    if not args_only:
        print("yo give me a normal file")
        return False
    root_directory = os.path.expanduser("~")
    try :
        for root, dirs, files in os.walk(root_directory):
            try:
                for file in files:
                    if file in args_only:
                        full_path = os.path.join(root,file)
                        if os.path.exists(full_path):

                            if os.access(full_path, os.X_OK):
                                print(f"{file} is executable")
                                return True
                            else:
                                current_mode = os.stat(full_path).st_mode
                                os.chmod(full_path , 0o770)
                                print(f"{file} will executable now to owner and group")
                                return True
            except(PermissionError , OSError):
                continue
    except KeyboardInterrupt:
        print("stopped by user")
    except Exception as e:
        print("shit happens")
    return False



if __name__ == "__main__":
    exe_check()

