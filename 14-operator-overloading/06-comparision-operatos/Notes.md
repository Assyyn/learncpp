# Minimizing comparative Redundancy

Many of the comparison operators can be implemented using the other comparison operators:

- operator!= can be implemented as !(operator==)
- operator> can be implemented as operator< with the order of the parameters flipped
- operator>= can be implemented as !(operator<)
- operator<= can be implemented as !(operator>)

This means that we only need to implement logic for operator== and operator<, and then the other four comparison operators can be defined in terms of those two!
