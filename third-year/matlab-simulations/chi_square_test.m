clc;
r = [36 91 51 02 54 06 58 06 58 02 54 01 48 97 43 22 83 25 79 95 42 87 73 17 02 42 95 38 79 29 65 09 55 97 39 83 31 77 17 62 03 49 90 37 13 17 58 11 51 92 33 78 21 66 09 54 49 90 35 84 26 74 22 62 12 90 36 83 32 75 31 94 34 87 40 07 58 05 56 22 58 77 71 10 73 23 57 13 36 89 22 68 02 44 99 27 81 26 85 82];
r_length = length(r);
fprintf('Total Students = %d\n', r_length);

for i = 1:r_length
    fprintf(' %d ', r(i));
end

fprintf('\n');

Acceptance_value = input('Enter acceptance value at that confidence level = ');
Expected = input('Enter Expected value = ');
E = Expected;
Range = Expected * Expected;
frequency = 0.0;
diff_square = 0.0;
i = 0;

while i < Range

    for j = 1:r_length

        if ((r(j) > i) && (r(j) <= Expected))
            frequency = frequency + 1;
        end

    end

    O = frequency;
    diff_square = diff_square + (abs(O - E))^2;

    fprintf('Difference Square = %d\n', frequency);
    i = i + E;
    Expected = Expected + E;
    frequency = 0;
end

chi_square = double(diff_square / E);
fprintf('\n\nChi Square value is = %.2f\n', chi_square);

if (Acceptance_value > chi_square)
    fprintf('\nThe random numbers follows the chi-square test. Because Chi Square value %.2f is less than Acceptance value %.2f\n', chi_square, Acceptance_value);
else
    fprintf('\nThe random numbers follows the chi-square test. Because Chi Square value %.2f is greater than Acceptance value %.2f\n', chi_square, Acceptance_value);
end

fprintf('\n\n');
