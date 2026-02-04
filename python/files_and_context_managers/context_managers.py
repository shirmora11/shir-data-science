import string
import os
import pathlib




def A_Z_generate():
    current_dir = pathlib.Path(".")
    for i in string.ascii_uppercase:
        file_path = current_dir / f"{i}.txt"
        try:
            with open(file_path,"x", encoding= "utf-8") as text:
                text.write(f"this is file{i}")
        except FileExistsError:
            print(f"file already exists")



            









