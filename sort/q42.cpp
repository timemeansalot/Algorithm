clear;clf; syms y(t);
D2y = diff(y,t,2);
D1y = diff(y,t);
eqn = D2y+3*D1y+6*y==0;
conds = [y(0)==0, D1y(0)==10];
solution = dsolve(eqn,conds); fplot(solution,[0 5]) xlabel('t')
ylabel('y')
title('the zero-input response');
