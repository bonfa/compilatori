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
		


	def test_es_02(self):
		#definisco il nome del file da testare
		name_file = "es_02.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)

		



	def test_es_03(self):
		#definisco il nome del file da testare
		name_file = "es_03.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)
		


	def test_es_04(self):
		#definisco il nome del file da testare
		name_file = "es_04.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)
		


	def test_es_05(self):
		#definisco il nome del file da testare
		name_file = "es_05.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)
		


	def test_es_06(self):
		#definisco il nome del file da testare
		name_file = "es_06.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)


	
	def test_es_07(self):
		#definisco il nome del file da testare
		name_file = "es_07.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)


	def test_es_08(self):
		#definisco il nome del file da testare
		name_file = "es_08.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)


	def test_es_09(self):
		#definisco il nome del file da testare
		name_file = "es_09.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)

		


	def test_es_10(self):
		#definisco il nome del file da testare
		name_file = "es_10.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



					
	def test_es_11(self):
		#definisco il nome del file da testare
		name_file = "es_11.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)
	



	def test_es_12(self):
		#definisco il nome del file da testare
		name_file = "es_12.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)
	


	def test_es_13(self):
		#definisco il nome del file da testare
		name_file = "es_13.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_14(self):
		#definisco il nome del file da testare
		name_file = "es_14.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_15(self):
		#definisco il nome del file da testare
		name_file = "es_15.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_16(self):
		#definisco il nome del file da testare
		name_file = "es_16.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_17(self):
		#definisco il nome del file da testare
		name_file = "es_17.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_18(self):
		#definisco il nome del file da testare
		name_file = "es_18.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)


	
	def test_es_19(self):
		#definisco il nome del file da testare
		name_file = "es_19.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)


	def test_es_20(self):
		#definisco il nome del file da testare
		name_file = "es_20.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_21(self):
		#definisco il nome del file da testare
		name_file = "es_21.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_22(self):
		#definisco il nome del file da testare
		name_file = "es_22.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)

	

	def test_es_23(self):
		#definisco il nome del file da testare
		name_file = "es_23.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_24(self):
		#definisco il nome del file da testare
		name_file = "es_24.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_25(self):
		#definisco il nome del file da testare
		name_file = "es_25.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_26(self):
		#definisco il nome del file da testare
		name_file = "es_26.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_27(self):
		#definisco il nome del file da testare
		name_file = "es_27.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_28(self):
		#definisco il nome del file da testare
		name_file = "es_28.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_29(self):
		#definisco il nome del file da testare
		name_file = "es_29.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_30(self):
		#definisco il nome del file da testare
		name_file = "es_30.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_31(self):
		#definisco il nome del file da testare
		name_file = "es_31.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_32(self):
		#definisco il nome del file da testare
		name_file = "es_32.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_33(self):
		#definisco il nome del file da testare
		name_file = "es_33.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_34(self):
		#definisco il nome del file da testare
		name_file = "es_34.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_35(self):
		#definisco il nome del file da testare
		name_file = "es_35.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_36(self):
		#definisco il nome del file da testare
		name_file = "es_36.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_37(self):
		#definisco il nome del file da testare
		name_file = "es_37.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_40(self):
		#definisco il nome del file da testare
		name_file = "es_40.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)


	def test_es_41(self):
		#definisco il nome del file da testare
		name_file = "es_41.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_42(self):
		#definisco il nome del file da testare
		name_file = "es_42.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_43(self):
		#definisco il nome del file da testare
		name_file = "es_43.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)


	def test_es_43(self):
		#definisco il nome del file da testare
		name_file = "es_43.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_44(self):
		#definisco il nome del file da testare
		name_file = "es_44.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)


	def test_es_45(self):
		#definisco il nome del file da testare
		name_file = "es_45.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_46(self):
		#definisco il nome del file da testare
		name_file = "es_46.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_47(self):
		#definisco il nome del file da testare
		name_file = "es_47.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_48(self):
		#definisco il nome del file da testare
		name_file = "es_48.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_49(self):
		#definisco il nome del file da testare
		name_file = "es_49.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_50(self):
		#definisco il nome del file da testare
		name_file = "es_50.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_51(self):
		#definisco il nome del file da testare
		name_file = "es_51.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_52(self):
		#definisco il nome del file da testare
		name_file = "es_52.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_53(self):
		#definisco il nome del file da testare
		name_file = "es_53.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_54(self):
		#definisco il nome del file da testare
		name_file = "es_54.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_55(self):
		#definisco il nome del file da testare
		name_file = "es_55.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_56(self):
		#definisco il nome del file da testare
		name_file = "es_56.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_57(self):
		#definisco il nome del file da testare
		name_file = "es_57.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)


	def test_es_58(self):
		#definisco il nome del file da testare
		name_file = "es_58.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_59(self):
		#definisco il nome del file da testare
		name_file = "es_59.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_60(self):
		#definisco il nome del file da testare
		name_file = "es_60.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_61(self):
		#definisco il nome del file da testare
		name_file = "es_61.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_62(self):
		#definisco il nome del file da testare
		name_file = "es_62.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_63(self):
		#definisco il nome del file da testare
		name_file = "es_63.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_64(self):
		#definisco il nome del file da testare
		name_file = "es_64.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)



	def test_es_65(self):
		#definisco il nome del file da testare
		name_file = "es_65.table"
		#chiamo il codice che fa il test
		self.do_test(name_file)

	


if __name__ == '__main__':
	suite = unittest.TestLoader().loadTestsFromTestCase(TestTableCompiler)
	unittest.TextTestRunner(verbosity=3).run(suite)
