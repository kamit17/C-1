def rSN(array):
    maxLen = -1
    # find max number and it's max length
    for number in array: # Find longest number, in digits
        numLen = int(math.log10(number)) + 1
        if numLen > maxLen:
            maxLen = numLen
    buckets = [[] for i in range(0, 10)] # Buckets for each digit
    # for each digit
    for digit in range(0, maxLen):
        for number in array:
            # divide number by 10^digit %10 and that is the index of the number
            buckets[number / 10**digit % 10].append(number)
        # delete array, so we can repopulate
        del array[:]
        for bucket in buckets:
            # add each bucket from lowest to highest radix to array
            array.extend(bucket)
            # delete all buckets content
            del bucket[:]
    return array
