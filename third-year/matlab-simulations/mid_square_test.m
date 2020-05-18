totalNumber = input('Number of Random Numbers want to generate : ');
choose = input('Enter the seed : ');
disp('Total Random Numbers are : ');

for i = 1:totalNumber
    random = choose^2;
    random = random / 100; % Find the dividend
    random = floor(rem(random, 10000)); % Get the reminder;
    choose = random;
    fprintf('%d ', random);
end

fprintf('\n');
