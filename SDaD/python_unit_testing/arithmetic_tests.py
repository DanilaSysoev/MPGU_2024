import unittest
from arithmetic import summ, division


test_case_number = 0


class TestArithmetic(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestArithmetic, self).__init__(*args, **kwargs)
    
    def setUp(self):
        global test_case_number
        print(f'setUp: {test_case_number}')
        
    def tearDown(self):
        global test_case_number
        print(f'tearDown: {test_case_number}')
        test_case_number += 1
        return super().tearDown()
    
    def test_summ_summ1and2_resultEqualsThree(self):
        print('test_summ_summ1and2_resultEqualsThree')
        self.assertEqual(summ(1, 2), 3)

    def test_summ_summn1andn3_resultEqualsnFour(self):
        print('test_summ_summn1andn3_resultEqualsnFour')
        self.assertEqual(summ(-1, -3), -4)

    def test_summ_summ2andn4_resultEqualsnTwo(self):
        print('test_summ_summ2andn4_resultEqualsnTwo')
        self.assertEqual(summ(2, -4), -2)

    def test_summ_summn3and6_resultEqualsThree(self):
        print('test_summ_summn3and6_resultEqualsThree')
        self.assertEqual(summ(-3, 6), 3)
    
    def test_divisionByZero_raisesZeroDivisionError(self):
        print('test_divisionByZero_raisesZeroDivisionError')
        with self.assertRaises(ZeroDivisionError):
            division(1, 0)


if __name__ == '__main__':
    unittest.main()
