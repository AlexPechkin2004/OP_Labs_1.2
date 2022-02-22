def input_file(filename):
    with open(filename, 'w') as infile:
        line = input("Enter text (ctrl + E and Enter to finish): \n")
        while line != chr(5):
            infile.write(line + "\n")
            line = input()


def output_file(filename):
    with open(filename, 'r') as file:
        lines = file.read().split("\n")
        for i in lines:
            print(i)


def modify_file(first_file_name, second_file_name):
    with open(first_file_name, 'r') as infile:
        with open(second_file_name, 'w') as outfile:
            lines = infile.read().split("\n")
            for line in lines:
                if line != "":
                    temp = line.replace(";", " ")
                    temp = temp.replace(",", " ")
                    words = temp.split()

                    max_count = 0
                    for j in range(len(words)):
                        if words.count(words[j]) > max_count:
                            max_count = words.count(words[j])

                    outfile.write(str(max_count) + " " + line + "\n")
