#Karol Dziekan
def input():
    return raw_input()

class Person:
    def __init__(self, name, surname):
        self.name = name
        self.surname = surname 
    def __str__(self):
        return 'name: {:10} surname: {:15}'.format(self.name, self.surname)
class Employee: 
    def __init__(self, person, experience, salary):
        self.person = person
        self.experience = experience
        self.salary = salary 
 
    def __str__(self): 
        return '{} experience: {:2} salary: {:5}'.format(self.person,self.experience, self.salary)



def Compare_Persons(a, b):
    if a.surname == b.surname:
        # <= jest wazne dla zachowania stabilnosci
        return a.name <= b.name
    else:
        return a.surname < b.surname



def Cocktail_sort(arr):
    arr_size = len(arr)
    swapped = True
    start = 0
    end = arr_size - 1

    while (swapped == True):
        #Przechodzimy od lewej do prawej
        #Kolejny element na koncu jest posortowany
        swapped = False

        for i in range(start, end):
            if (not Compare_Persons(arr[i].person, arr[i + 1].person)):
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True
 
        if (swapped == False):
            break

        #Przechodzimy od prawej do lewej
        #Kolejny element na poczatku jest posortowany
        swapped = False
        end = end - 1

        for i in range(end - 1, start - 1, -1):
            if (not Compare_Persons(arr[i].person, arr[i + 1].person)):
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True

        start = start + 1



def Selection_sort(arr):
    n = len(arr)

    #Po i-tej iteracji znajdujemy i-ty element w tablicy i ustawiamy go na i-tej pozycji
    #Wtedy pierwsze i elementow z przodu jest posortowanych
    for i in range(n):
        min_idx = i

        for j in range(i + 1, n):
            if arr[min_idx].salary > arr[j].salary:
                min_idx = j

        key = arr[min_idx]

        arr[i], arr[min_idx] = arr[min_idx], arr[i]



def Count_sort(arr):
    arr_size = len(arr)
    maximum_experience = 0

    for i in arr:
        if i.experience > maximum_experience:
            maximum_experience = i.experience

    #Zliczamy ile razy wystepuje dana liczba
    count_array = [0] * (maximum_experience + 1)
    for num in arr:
        count_array[num.experience] += 1

    #Tworzymy tablice prefiksowa
    for i in range(1, maximum_experience + 1):
        count_array[i] += count_array[i - 1]

    #Odczytujemy odpowiednia pozycje dla kazdego elementu z poczatkowej tablicy do nowej tablicy
    output_array = [0] * arr_size
    for i in range(arr_size - 1, -1, -1):
        output_array[count_array[arr[i].experience] - 1] = arr[i]
        count_array[arr[i].experience] -= 1

    arr[:] = output_array


names = input().split()
surnames = input().split()
experience = input().split()
salaries = input().split()

employe_list = []

for i in range(len(names)):
    employe = Employee(Person(names[i], surnames[i]), int(experience[i]), int(salaries[i]))
    employe_list.append(employe)

Selection_sort(employe_list)
Count_sort(employe_list)
Cocktail_sort(employe_list)



for i in employe_list:
    print(i)