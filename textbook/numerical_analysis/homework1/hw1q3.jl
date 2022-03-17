import LinearAlgebra.I

struct ADV
    v # value
    d # derivative
end

function Base.:exp(x::ADV)
    return ADV(exp(x.v), exp(x.v) * x.d);
end
function Base.:+(x::ADV, y::ADV)
    return ADV(x.v + y.v, x.d + y.d);
end
function Base.:/(x::ADV, y::ADV)
    return ADV(x.v / y.v, (x.d*y.v - y.d*x.v) / y.v^2);
end

# Original function f(x)
f(x) = exp(x[2]) / (exp(x[1]) + exp(x[2]) + exp(x[3]));

# Hand-derived
∇f(x) = [
    - exp(x[2]) * exp(x[1]);
    exp(x[2]) * (exp(x[1]) + exp(x[3]));
    - exp(x[2]) * exp(x[3])
] ./ (exp(x[1]) + exp(x[2]) + exp(x[3]))^2;

x = [5.0; 6.0; 7.0];
x_AD = hcat([[ADV(v,d) for (v,d) = zip(x,e)] for e = eachcol(Matrix{Float64}(I, 3, 3))]);
f_eval = [f(xi) for xi = x_AD];
∇f_AD = [f.d for f in f_eval];
error = abs.(∇f_AD - ∇f(x));

println("Algorithmic Differentiation Result")
display(∇f_AD)
println("Error")
display(error)