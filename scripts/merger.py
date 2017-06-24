import os
import re
import sys

output_dir = "D:/git-workspace/WonderDev/toto/generated_src"
output_file = "D:/git-workspace/WonderDev/toto/generated_src/codingame.cpp"

excluded_files = ["inGameMain.txt", "Algo.cpp", "Algo.h", "Evaluation.cpp", "Evaluation.h"]

include_regex = r"#include \"([\w\.]+)\""

processed_files = []


def run():
    working_dir = sys.argv[1]

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    # clean
    with open(output_file, "w") as output:
        output.write("")
    process_file(os.path.join(working_dir, "inGameMain.txt"), False)
    process_dir(working_dir)


def process_dir(working_dir):
    files = [f for f in os.listdir(working_dir) if os.path.isfile(os.path.join(working_dir, f))]

    for file in files:
        if file not in excluded_files:
            process_file(os.path.join(working_dir, file), False)


def process_file(file, is_included):
    if file.endswith(".h") and not is_included:
        return
    if file.endswith("main.cpp"):
        print "main.cpp excluded"
        return
    elif file.endswith(".cpp"):
        print "Processing " + file
        with open(output_file, "a") as output:
            output.write("/*-- File: " + file + " start --*/\n")
    elif file.endswith(".h"):
        print "Including " + file
        with open(output_file, "a") as output:
            output.write("/*-- #include \"" + file + "\" start --*/\n")
    else:
        print "Ignoring " + file

    if file not in processed_files:

        with open(file, "r") as input:
            for line in input:
                if line.startswith("#include \""):
                    m = re.match(include_regex, line)
                    if m:
                        included_file = os.path.join(os.path.dirname(file), m.group(1))
                        print "Found a file to include : " + included_file
                        process_file(included_file, True)
                    else:
                        print "warning : " + line
                elif line.startswith("#pragma once"):
                    processed_files.append(file)
                else:
                    with open(output_file, "a") as output:
                        output.write(line)


    if file.endswith(".cpp"):
        with open(output_file, "a") as output:
            output.write("/*-- File: " + file + " end --*/\n")
    elif file.endswith(".h"):
        with open(output_file, "a") as output:
            output.write("/*-- #include \"" + file + "\" end --*/\n")


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print "Usage : merger.py path_to_sources_files"
        print "Example : merger.py D:/git-workspace/WonderDev/toto/src"
    else:
        run()