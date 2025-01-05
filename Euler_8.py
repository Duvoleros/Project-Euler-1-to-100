string = "".join(input().split(' '))
string = string.split('0')
final_string = []
for line in string:
    if(len(line)>=13):
        final_string.append(line)
print (final_string)
final_rez = 0
for line in final_string:
    temp_rez = 1
    for i in range(0,13):
        temp_rez*=int(line[i])
    if(final_rez<temp_rez):
        final_rez = temp_rez
    for i in range(13, len(line)):
        temp_rez/=int(line[i-13])
        temp_rez*=int(line[i])
        if(final_rez<temp_rez):
            final_rez = temp_rez
print(final_rez)
