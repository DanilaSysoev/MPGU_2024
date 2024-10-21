import str_extension as se
import unittest

class StrExtensionTests(unittest.TestCase):
    def test_max_cnt_symbols(self):
        self.assertEqual(sorted(se.max_cnt_symbols('abcd')), sorted('abcd'))
        
    def test_min_cnt_symbols(self):
        self.assertEqual(se.min_cnt_symbols('aaaabb'), 'b')
        
    def test_unique_symbols(self):
        self.assertEqual(sorted(se.unique_symbols('aabbbccddd')), sorted('abcd'))
        
    def test_get_words(self):
        self.assertEqual(se.get_words('a,b.s d', ',. '), ['a', 'b', 's', 'd'])

    def test_get_names(self):
        self.assertEqual(se.names('hello worrld, my name is Danila'), ['Danila'])


if __name__ == '__main__':
    unittest.main()
