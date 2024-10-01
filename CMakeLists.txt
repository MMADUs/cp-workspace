cmake_minimum_required(VERSION 3.29)
project(fundamental C)

set(CMAKE_C_STANDARD 11)

# Add executable for main.c
add_executable(main_exec
        basic.c)

# Add executable for even-odd.c
add_executable(even_odd_exec
        even-odd.c)

# Add executable for instant-ramen.c
add_executable(instant_ramen_exec
        instant-ramen.c)

# Add executable for cashback.c
add_executable(cashback_exec
        cashback.c)

# Add executable for frog-party.c
add_executable(frog_party_exec
        frog-party.c)

# Add executable for not-equal.c
add_executable(not_equal_exec
        not-equal.c)

# Add executable for traditional-market.c
add_executable(traditional_market_exec
        traditional-market.c)

# Add executable for are-they-equal.c
add_executable(are_they_equal_exec
        are-they-equal.c)

# Add executable for alphabetical-order.c
add_executable(alphabetical_order_exec
        alphabetical-order.c)

# Add executable for terms-condition.c
add_executable(terms_condition_exec
        terms-condition.c)

# Add executable for three-elevators.c
add_executable(three-elevators_exec
        three-elevators.c)
