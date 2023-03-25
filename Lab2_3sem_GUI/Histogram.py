import matplotlib.pyplot as plt

text = ''
file = open('Lab2_histogram.txt', "r")
distr_number = list(file.readline())[0]
if distr_number == '1' :
    text = 'Poisson distribution'
elif distr_number == '2' :
    text = 'Uniform distribution'
data = []
while True :
    line = list(file.readline())
    if len(line) == 0 :
        break
    if len(line) != 1 :
        line.pop()
    data.append(int(''.join(line)))
    if not line :
        break
file.close()

distr = 50
plt.hist(data, bins = distr, facecolor="blue", edgecolor="black", alpha=0.7)
# Показать метку горизонтальной оси
plt.xlabel('interval')
# Отображение метки вертикальной оси
plt.ylabel('Frequency')
# Показать название изображения
plt.title(text)
plt.show()