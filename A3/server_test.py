import unittest
from server import is_prime, compute_primes

class TestServer(unittest.TestCase):

    def test_is_prime(self):
        self.assertFalse(is_prime(0))
        self.assertFalse(is_prime(1))
        self.assertTrue(is_prime(2))
        self.assertTrue(is_prime(3))
        self.assertFalse(is_prime(4))
        self.assertTrue(is_prime(5))
        self.assertTrue(is_prime(13))
        self.assertFalse(is_prime(15))

    def test_compute_primes(self):
        self.assertEqual(compute_primes(0, 10), [2, 3, 5, 7])
        self.assertEqual(compute_primes(10, 20), [11, 13, 17, 19])
        self.assertEqual(compute_primes(20, 30), [23, 29])
        self.assertEqual(compute_primes(30, 40), [31, 37])
        self.assertEqual(compute_primes(50, 60), [53, 59])

if __name__ == "__main__":
    unittest.main()
