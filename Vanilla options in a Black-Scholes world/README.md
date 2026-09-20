# Vanilla options in a Black-Scholes world

The purpose of this project is to implement the pricing of some vanilla options
with the Black-Scholes model by multiple methods. Some of the functions implemented
here will be extremely useful for other projects.

## Formulas

The first thing to do is to implement the Black-Scholes formulas for various
options:

* Implement the price of a forward as a function of time-to-maturity, $T$,
continuously compounding rate, $r$, dividend rate, $d$, strike, $K$, spot, $S$,
and volatility, $\sigma$.
* Ditto for a call option.
* Ditto for a put option.
* Ditto for a digital-call option.
* Ditto for a digital-put option.
* Ditto for a zero-coupon bond.

## Consistency

We need to be sure that the formulas have been implemented correctly so run the
following consistency checks.

1. We should have put-call parity: the price of a call minus the price of a put
equals the value of a forward.
1. The price of a call option should be monotone decreasing with strike.
1. A call option price should be between $S$ and $S - K e^{-r T}$, for all inputs.
1. A call option price should be monotone increasing in volatility.
1. If $d = 0$, the call option price should be increasing with $T$.
1. The call option price should be a convex function of strike.
1. The price of a call-spread should approximate the price of a digital-call
option.
1. The price of a digital-call option plus a digital-put option is equal to the
price of a zero-coupon bond.

## Validation via Monte Carlo

We want to test the prices against a Monte Carlo simulation. It is worthwhile
writing code to work using a random number generator class which can then be
changed later on. This will allow you to check whether the random number generator
is biased, and also to easily plug in a low-discrepancy generator at a later time.
Each path in any Monte Carlo simulation will require a certain number of random
draws. The maximum number needed is the _dimensionality_. It is best to set-up the
class to draw a vector of this size from the random number generator at the start
of each run, and make sure the random number generator is actually capable of that
dimensionality. Several methods of generating random numbers are given in [123].
Once you have done this, you should

1. Implement an engine which randomly evolves a stock price from time 0 to time
$T$ according to a geometric Brownian motion with drift $r - d$,
and volatility $\sigma$. Use the formula

$$S_T = S_0 e^{(r-d) T - \frac{1}{2} \sigma^2 T + \sigma \sqrt{T} W}$$

where $W$ is a standard normal random variable.
1. Use the engine to write Monte Carlo pricers for all the products mentioned
above. The engine generates a final stock value. The option's pay-off for that
final value is then evaluated and discounted. These values are then averaged
over a large number of paths. Get it to return the price for successive powers
of two for the number of paths so you can see the convergence. Also get it to
return the variance of the samples and standard error.
When implementing the pricer and the engine try to do it in an orthogonal way so
that the engine just takes in an option object which states its pay-off and expiry.
If done correctly, the engine should then need no modifications when a new option
type, such as a straddle, is added in. Also the option objects can then be reused
when doing Monte Carlo simulations based on different engines.
We can now run some tests.

1. Compute Monte Carlo and formula prices for a large range of inputs for each
of the options above. They should all agree up to the degree of convergence of
the Monte Carlo.
If the above tests worked, we can be reasonably confident in both our
Black-Scholes functions and in our Monte Carlo engine.

## Investigations

We can now use these routines for implementing tougher projects and doing some
investigations.

1. How does the Black-Scholes price of a call option vary as a function pay-off
volatility? What happens when volatility is zero, or volatility is very large?
1. What about a digital call option?
1. For various at-the-money call options, how does the price vary with volatility?
Plot the ratio of price to volatility.
1. For various put options plot the price and intrinsic value on the same graph.
Find at least one example where the two graphs cross.

## Stepping methods

One further thing to implement is an alternative engine based on Euler stepping.
Divide the time, $T$, into a large number of steps, $N$. Let

$$\Delta t = T / N.$$

Evolve the stock price across each step by

$$S_{(j+1) \Delta T} = S_{j \Delta T} + r S_{j \Delta T} \Delta T + S_{j \Delta T } \sigma \sqrt{\Delta T} W_j ,$$

where the $W_j$ are independent normal variables. Running up to the last step this
gives an alternate way of generating the final stock value. Use this to develop
pricers for the basic options above. The engine will need as inputs the number
of steps and the number of paths.

1. Plot the final price as a function of the number of steps to see how many steps
are required for convergence.
1. Compare the number of paths required for the two Monte Carlo methods to
get a given degree of convergence.
1. Make sure the two methods give the same prices.
1. Compare the times required to get a given level of accuracy.
