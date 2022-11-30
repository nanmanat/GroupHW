int digit = cal_digit(product);
            int multiplier = pow(10, digit);
            for (int j = 0; j <= digit; j++)
            {
                answer[7 + i + 4 + j] = ((product / multiplier) % 10) + '0';
                multiplier /= 10;
            }