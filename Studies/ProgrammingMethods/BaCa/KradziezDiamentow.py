#Karol Dziekan

def input():
    return raw_input()


def solve():
    tab = input().split()

    rozmiar_plecaka = int(tab[0])

    tab = list(map(int, tab[1:]))

    ilosc_przedmiotow = len(tab)  // 2

    wagi_przedmiotow = [0] * ilosc_przedmiotow
    wartosci_przedmiotow = [0] * ilosc_przedmiotow

    for i in range(ilosc_przedmiotow):
        wartosci_przedmiotow[i] = tab[i * 2]
        wagi_przedmiotow[i] = tab[i * 2 + 1]

    
    knapsack_dp = [(0,0)] * (rozmiar_plecaka + 1)

    for i in range(ilosc_przedmiotow):
        for j in range(rozmiar_plecaka, wagi_przedmiotow[i] - 1, -1):
            knapsack_dp[j] = max((knapsack_dp[j][0], knapsack_dp[j][1]), (knapsack_dp[j - wagi_przedmiotow[i]][0] + wartosci_przedmiotow[i], knapsack_dp[j - wagi_przedmiotow[i]][1] + 1))

    print(knapsack_dp[rozmiar_plecaka][0])


testy = int(input())
while(testy != 0):
    solve()
    testy -= 1