#/usr/bin/python
# -*- coding: utf-8 -*-
'''
Testa il compilatore. Generatore di codice disponibile a questa pagina (http://linguaggi.ing.unibs.it/testable)
'''

import sys
import unittest
from subprocess import Popen, PIPE, STDOUT



def write_on_file(path_file,text):
	out_file = open(path_file,"w")
	out_file.write(text)
	out_file.close()



class TestTableCompiler(unittest.TestCase):
	'''
	Casi di test per le operazioni definite nel modulo base_crypto_utility.py
	'''
	def setUp(self):
		self.path = "./"
		self.path_file_table = self.path + "esempi_table/"
		self.path_file_esatti = self.path + "test_results/codice_esatto/"
		self.path_file_generati = self.path + "test_results/codice_generato/"
		self.path_compiler = self.path + "table"

	
	def do_test(self,name_file):
		'''
		Metodo generale che prende il nome del file in input e fa il test
		'''
		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_esatti + name_file ],stdout=PIPE)
			
		# leggo da file il risultato corretto
		codice_esatto = (p_printer.communicate()[0])

		#definisco il processo che stampa il codice sorgente
		p_printer = Popen(['cat',self.path_file_table+name_file],stdout=PIPE)
	
		#definisco il processo che prende in ingresso il sorgente e genera il codice
		p_compiler = Popen([self.path_compiler], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
		#imposto stdin di p_compiler come l'stdout di p_printer
		p_compiler.stdin.write(p_printer.communicate()[0])
		#estraggo l'stdout di p_tree 
		codice_generato = p_compiler.communicate()[0]

		#salvo il codice generato su file
		write_on_file(self.path_file_generati+name_file,codice_generato)

		#controllo	
		self.assertEqual(codice_esatto,codice_generato)		



	def test_es_00(self):
		#definisco il nome del file da testare
		name_file = "es_00.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)


	def test_es_01(self):
		#definisco il nome del file da testare
		name_file = "es_01.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)
		


	'''def test_es_02(self):
		

		



	def test_es_03(self):
		


	def test_es_04(self):
		


	def test_es_05(self):
		


	def test_es_06(self):
		


	
	def test_es_07(self):
		


	def test_es_08(self):
		


	def test_es_09(self):
		


	def test_es_10(self):
		


					
	def test_es_11(self):
		



	def test_es_12(self):'''
	
	




if __name__ == '__main__':
	suite = unittest.TestLoader().loadTestsFromTestCase(TestTableCompiler)
	unittest.TextTestRunner(verbosity=3).run(suite)
