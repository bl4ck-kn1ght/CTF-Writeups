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


def r_(c): 
    with open(c[0]+"/README.md","w") as r_file:
         r_file.write("# {}".format(string.capwords(c[1].replace("_"," "))))

for k,v in challenges.items():
    if not os.path.exists(k):
        os.mkdir(k)
    os.chdir(k)
    [os.mkdir(c) and r_((c,c)) for c in v if c not in os.listdir()]
    os.chdir(BASE_DIR)

r_((".","africa_hackon")) if not os.path.exists("README.md") else None