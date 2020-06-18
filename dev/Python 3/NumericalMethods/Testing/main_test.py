#import pytest
from ..Roots import *



def test_bisection():
    f = lambda x: x**2 + 2*x + 10
    assert bisection(f, [-100,100]) == -1