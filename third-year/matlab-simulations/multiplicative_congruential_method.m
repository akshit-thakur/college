%% r(i+1) = (ar(i)) mod m
clc;
a = input('Please Enter the value of a : ');
m = input('Please Enter the value of m : ');
r = input('Please Enter the value of seed or r : ');

totalNumber = input('Number of Random Numbers want to generate : ');

for i = 1:totalNumber
    r = mod(a * r, m);
    fprintf('%4.0f ', r);
end

fprintf('\n');
