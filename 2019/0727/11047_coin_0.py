def main():
    num_coin, change = map(int, input().split())
    coins = []

    for _ in range(num_coin):
        coins.append(int(input()))

    coins.sort()
    coins.reverse()

    result_coin = 0

    for i, coin in enumerate(coins):
        if change // coins[i] > 0:
            result_coin += change // coins[i]
            if change % coins[i] == 0:
                break
            else:
                change = change % coins[i]

    print(result_coin)

if __name__ == "__main__":
    main()
