import os, string 

challenges = {
    "crypto":["try_me","manifesto"],
    "malware_analysis":["cracks_by_jong","malchall_one","malchall_two"],
    "mobile":["bitwise_sacco"],
    "pwnable":["iam_free","namecheck"],
    "reversing":["command_parser"],
    "steganography":["waves","eventuary"],
    "web":["access_right_authentication","easy_flag","the_ultimate_tool"]
}
BASE_DIR = os.getcwd()


def c_dir_readme(c):
    os.mkdir(c)
    with open(c+"/README.md","w")as r_file:
        r_file.write("# {}".format(string.capwords(c.replace("_"," "))))
    return 

for k,v in challenges.items():
    if not os.path.exists(k):
        os.mkdir(k)
    os.chdir(k)
    [c_dir_readme(c) for c in v if c not in os.listdir()]
    os.chdir(BASE_DIR)

