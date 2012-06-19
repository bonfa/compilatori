#/usr/bin/python
# -*- coding: utf-8 -*-
'''
Testa il parser creato con yacc. Il risultato viene paragonato con il risultato del parser a discesa ricorsiva.
'''
import sys
#sys.path.append('/media/DATA/06-WorkSpace/netsec_wp/src/crypto')
import unittest
from subprocess import Popen, PIPE, STDOUT



class TestYaccParser(unittest.TestCase):
	'''
	Casi di test per le operazioni definite nel modulo base_crypto_utility.py
	'''
	def setUp(self):
		self.path = "../"
		self.path_parser_discesa_ricorsiva = self.path + "albero/sintattico"
		self.path_file_table = self.path + "albero/esempi_table/"
		self.path_parser_yacc = self.path + "yacc/parser"


	def test_es_00(self):
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_0.table"],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_discesa_ricorsiva = Popen([self.path_parser_discesa_ricorsiva], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_tree come l'stdout di p_printer
		p_discesa_ricorsiva.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_discesa_ricorsiva = p_discesa_ricorsiva.communicate()[0]


		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_0.table"],stdout=PIPE)

		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_yacc = Popen([self.path_parser_yacc], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_yacc come l'stdout di p_printer
		p_yacc.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_yacc = p_yacc.communicate()[0]

		#controllo	
		self.assertEqual(tree_discesa_ricorsiva,tree_yacc)		


	def test_es_01(self):
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_1.table"],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_discesa_ricorsiva = Popen([self.path_parser_discesa_ricorsiva], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_tree come l'stdout di p_printer
		p_discesa_ricorsiva.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_discesa_ricorsiva = p_discesa_ricorsiva.communicate()[0]


		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_1.table"],stdout=PIPE)

		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_yacc = Popen([self.path_parser_yacc], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_yacc come l'stdout di p_printer
		p_yacc.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_yacc = p_yacc.communicate()[0]

		#controllo	
		self.assertEqual(tree_discesa_ricorsiva,tree_yacc)
		


	def test_es_02(self):
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_2.table"],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_discesa_ricorsiva = Popen([self.path_parser_discesa_ricorsiva], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_tree come l'stdout di p_printer
		p_discesa_ricorsiva.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_discesa_ricorsiva = p_discesa_ricorsiva.communicate()[0]


		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_2.table"],stdout=PIPE)

		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_yacc = Popen([self.path_parser_yacc], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_yacc come l'stdout di p_printer
		p_yacc.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_yacc = p_yacc.communicate()[0]

		#controllo	
		self.assertEqual(tree_discesa_ricorsiva,tree_yacc)



	def test_es_03(self):
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_3.table"],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_discesa_ricorsiva = Popen([self.path_parser_discesa_ricorsiva], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_tree come l'stdout di p_printer
		p_discesa_ricorsiva.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_discesa_ricorsiva = p_discesa_ricorsiva.communicate()[0]


		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_3.table"],stdout=PIPE)

		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_yacc = Popen([self.path_parser_yacc], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_yacc come l'stdout di p_printer
		p_yacc.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_yacc = p_yacc.communicate()[0]

		#controllo	
		self.assertEqual(tree_discesa_ricorsiva,tree_yacc)


	def test_es_04(self):
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_4.table"],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_discesa_ricorsiva = Popen([self.path_parser_discesa_ricorsiva], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_tree come l'stdout di p_printer
		p_discesa_ricorsiva.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_discesa_ricorsiva = p_discesa_ricorsiva.communicate()[0]


		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_4.table"],stdout=PIPE)

		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_yacc = Popen([self.path_parser_yacc], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_yacc come l'stdout di p_printer
		p_yacc.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_yacc = p_yacc.communicate()[0]

		#controllo	
		self.assertEqual(tree_discesa_ricorsiva,tree_yacc)


	def test_es_05(self):
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_5.table"],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_discesa_ricorsiva = Popen([self.path_parser_discesa_ricorsiva], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_tree come l'stdout di p_printer
		p_discesa_ricorsiva.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_discesa_ricorsiva = p_discesa_ricorsiva.communicate()[0]


		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_5.table"],stdout=PIPE)

		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_yacc = Popen([self.path_parser_yacc], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_yacc come l'stdout di p_printer
		p_yacc.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_yacc = p_yacc.communicate()[0]

		#controllo	
		self.assertEqual(tree_discesa_ricorsiva,tree_yacc)


	def test_es_06(self):
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_6.table"],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_discesa_ricorsiva = Popen([self.path_parser_discesa_ricorsiva], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_tree come l'stdout di p_printer
		p_discesa_ricorsiva.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_discesa_ricorsiva = p_discesa_ricorsiva.communicate()[0]


		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_6.table"],stdout=PIPE)

		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_yacc = Popen([self.path_parser_yacc], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_yacc come l'stdout di p_printer
		p_yacc.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_yacc = p_yacc.communicate()[0]

		#controllo	
		self.assertEqual(tree_discesa_ricorsiva,tree_yacc)


	
	def test_es_07(self):
		'''
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_7.table"],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_discesa_ricorsiva = Popen([self.path_parser_discesa_ricorsiva], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_tree come l'stdout di p_printer
		p_discesa_ricorsiva.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_discesa_ricorsiva = p_discesa_ricorsiva.communicate()[0]


		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_7.table"],stdout=PIPE)

		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_yacc = Popen([self.path_parser_yacc], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_yacc come l'stdout di p_printer
		p_yacc.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_yacc = p_yacc.communicate()[0]

		#controllo	
		self.assertEqual(tree_discesa_ricorsiva,tree_yacc)
		'''


	def test_es_08(self):
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_8.table"],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_discesa_ricorsiva = Popen([self.path_parser_discesa_ricorsiva], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_tree come l'stdout di p_printer
		p_discesa_ricorsiva.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_discesa_ricorsiva = p_discesa_ricorsiva.communicate()[0]


		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_8.table"],stdout=PIPE)

		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_yacc = Popen([self.path_parser_yacc], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_yacc come l'stdout di p_printer
		p_yacc.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_yacc = p_yacc.communicate()[0]

		#controllo	
		self.assertEqual(tree_discesa_ricorsiva,tree_yacc)


	def test_es_09(self):
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_9.table"],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_discesa_ricorsiva = Popen([self.path_parser_discesa_ricorsiva], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_tree come l'stdout di p_printer
		p_discesa_ricorsiva.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_discesa_ricorsiva = p_discesa_ricorsiva.communicate()[0]


		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_9.table"],stdout=PIPE)

		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_yacc = Popen([self.path_parser_yacc], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_yacc come l'stdout di p_printer
		p_yacc.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_yacc = p_yacc.communicate()[0]

		#controllo	
		self.assertEqual(tree_discesa_ricorsiva,tree_yacc)


	def test_es_10(self):
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_10.table"],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_discesa_ricorsiva = Popen([self.path_parser_discesa_ricorsiva], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_tree come l'stdout di p_printer
		p_discesa_ricorsiva.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_discesa_ricorsiva = p_discesa_ricorsiva.communicate()[0]


		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_10.table"],stdout=PIPE)

		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_yacc = Popen([self.path_parser_yacc], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_yacc come l'stdout di p_printer
		p_yacc.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_yacc = p_yacc.communicate()[0]

		#controllo	
		self.assertEqual(tree_discesa_ricorsiva,tree_yacc)



	def test_es_11(self):
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_11.table"],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_discesa_ricorsiva = Popen([self.path_parser_discesa_ricorsiva], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_tree come l'stdout di p_printer
		p_discesa_ricorsiva.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_discesa_ricorsiva = p_discesa_ricorsiva.communicate()[0]


		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_11.table"],stdout=PIPE)

		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_yacc = Popen([self.path_parser_yacc], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_yacc come l'stdout di p_printer
		p_yacc.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_yacc = p_yacc.communicate()[0]

		#controllo	
		self.assertEqual(tree_discesa_ricorsiva,tree_yacc)



	def test_es_12(self):
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_12.table"],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_discesa_ricorsiva = Popen([self.path_parser_discesa_ricorsiva], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_tree come l'stdout di p_printer
		p_discesa_ricorsiva.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_discesa_ricorsiva = p_discesa_ricorsiva.communicate()[0]


		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+"es_12.table"],stdout=PIPE)

		#definisco il processo che prende in ingresso il sorgente e genera l'albero
		p_yacc = Popen([self.path_parser_yacc], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_yacc come l'stdout di p_printer
		p_yacc.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		tree_yacc = p_yacc.communicate()[0]

		#controllo	
		self.assertEqual(tree_discesa_ricorsiva,tree_yacc)




if __name__ == '__main__':
	suite = unittest.TestLoader().loadTestsFromTestCase(TestYaccParser)
	unittest.TextTestRunner(verbosity=2).run(suite)
