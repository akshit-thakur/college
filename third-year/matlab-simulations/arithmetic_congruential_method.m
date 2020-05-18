%% r(i + 1) = (r(i) + r(i - 1)) percent m
clc;
N = input('Enter How Many Number You want to generate = ');
r0 = input('Enter First Random Number = ');
r1 = input('Enter Second Random Number = ');
m = input('Enter Maximum Range Of Random Number = ');

for i = 1:N
    r2 = r0 + r1;
    random = mod(r2, m);
    fprintf('%d ', random);
    r0 = r1;
    r1 = r2;
end
