#include "unittest.h"
#include <iostream>
#include <iomanip>
#include "Vector2"
#include "Vector3"
#include "Vector4"

#ifndef NO_DEFAULT_STREAM_OPERATOR

	std::ostream& operator << (std::ostream& os, Vector2& rhs) { 
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1]; return os; }
	std::ostream& operator << (std::ostream& os, Vector3& rhs) {
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1] << "," << std::setprecision(12) << a[2]; return os; }
	//std::ostream& operator << (std::ostream& os, Vector4& rhs) {
	//	float* a = (float*)rhs;
	//	os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1] << "," << std::setprecision(12) << a[2] << "," << std::setprecision(12) << a[3]; return os; }
	//std::ostream& operator << (std::ostream& os, Matrix2& rhs) {
	//	float* a = (float*)rhs;
	//	for (int i = 0; i < 4; ++i) {
	//		os << std::setprecision(12) << a[i];
	//		if (!(i == 3 ))
	//			os << ",";
	//	}
	//	return os;
	//}
	//std::ostream& operator << (std::ostream& os, Matrix3& rhs) {
	//	float* a = (float*)rhs;
	//	for (int i = 0; i < 9; ++i) {
	//		os << std::setprecision(12) << a[i];
	//		if (!(i == 8))
	//			os << ",";
	//	}
	//	return os;
	//}
	//std::ostream& operator << (std::ostream& os, Matrix4& rhs) {
	//	float* a = (float*)rhs;
	//	for (int i = 0; i < 16; ++i) {
	//		os << std::setprecision(12) << a[i];
	//		if (!(i == 15))
	//			os << ",";
	//	}
	//	return os;
	//}

#endif

static const float DEFAULT_TOLERANCE = 0.00001f;

bool compare(float a, float b, float tolerance = DEFAULT_TOLERANCE) {
	if (abs(a - b) > tolerance)
		return false;
	return true;
}

bool compare( Vector2& A,  Vector2& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = (float*)A;
	 float* b = (float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance)
		return false;
	return true;
}

bool compare( Vector3& A,  Vector3& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance || 
		abs(a[2] - b[2]) > tolerance)
		return false;
	return true;
}

//bool compare( Vector4& A,  Vector4& B, float tolerance = DEFAULT_TOLERANCE) {
//	 float* a = ( float*)A;
//	 float* b = ( float*)B;
//	if (abs(a[0] - b[0]) > tolerance || 
//		abs(a[1] - b[1]) > tolerance || 
//		abs(a[2] - b[2]) > tolerance || 
//		abs(a[3] - b[3]) > tolerance)
//		return false;
//	return true;
//}

//bool compare( Matrix2& A,  Matrix2& B, float tolerance = DEFAULT_TOLERANCE) {
//	 float* a = ( float*)A;
//	 float* b = ( float*)B;
//	if (abs(a[0] - b[0]) > tolerance || abs(a[1] - b[1]) > tolerance ||
//		abs(a[2] - b[2]) > tolerance || abs(a[3] - b[3]) > tolerance)
//		return false;
//	return true;
//}

//bool compare( Matrix3& A,  Matrix3& B, float tolerance = DEFAULT_TOLERANCE) {
//	 float* a = ( float*)A;
//	 float* b = ( float*)B;
//	if (abs(a[0] - b[0]) > tolerance || abs(a[1] - b[1]) > tolerance || abs(a[2] - b[2]) > tolerance ||
//		abs(a[3] - b[3]) > tolerance || abs(a[4] - b[4]) > tolerance || abs(a[5] - b[5]) > tolerance ||
//		abs(a[6] - b[6]) > tolerance || abs(a[7] - b[7]) > tolerance || abs(a[8] - b[8]) > tolerance)
//		return false;
//	return true;
//}

//bool compare( Matrix4& A,  Matrix4& B, float tolerance = DEFAULT_TOLERANCE) {
//	 float* a = ( float*)A;
//	 float* b = ( float*)B;
//	if (abs(a[0] - b[0]) > tolerance || abs(a[1] - b[1]) > tolerance || abs(a[2] - b[2]) > tolerance || abs(a[3] - b[3]) > tolerance ||
//		abs(a[4] - b[4]) > tolerance || abs(a[5] - b[5]) > tolerance || abs(a[6] - b[6]) > tolerance || abs(a[7] - b[7]) > tolerance ||
//		abs(a[8] - b[8]) > tolerance || abs(a[9] - b[9]) > tolerance || abs(a[10] - b[10]) > tolerance || abs(a[11] - b[11]) > tolerance ||
//		abs(a[12] - b[12]) > tolerance || abs(a[13] - b[13]) > tolerance || abs(a[14] - b[14]) > tolerance || abs(a[15] - b[15]) > tolerance)
//		return false;
//	return true;
//}

template <typenam
	   $ 
	�
	$                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    �nb	�\a`  " � @     ��    �  �  �          D       � �@  " @          @    � ��  !      �          @      @          �   �  �  @           0   	 �     �  �   �                  ��� A � "         <�@    � �$&�         mF DD�  Ȑ`J  Ģ @ H�� ��V A B    ,��  � @�  �D )
	       � (B   �  �     @   	  (      �       @  ��    
		 0    � H �            @ �!    "  @              ��  � P               (�  @ H�    @"�   @($@  @ �     	    �  @                  @                     @ @ @  @           A@� �          �  @�! B � (  @��� �  $ h� �     �   �  $b ��;� �    h���!h"    `c� J �  b@�@�&,    �*D (�   ��   �     @     �
			"   ��ZP�      A  �  H`  @    �      �
			 !�           	         �       �   P        �            �   
			  2  @  � @   �na	�\` @      �@(0    @       � �
			�  @	 �   � "   � 0) � ���@  `  D @        	 	        $    �       & A�    �  �   @  (`(  @�	`  �
			  �   � B@�D� !� ��  �   
			`  �)  �B  i$x 0(�Y @  �  ��    ����DXA  be��!�`"� �0�� $� p�`B��D@Ae UgN�� �% Ihc�  �`8 �*�B H �
				    � @        
				@   � @�@    ��    �  @ P $ � *    @(     �  ��� �     @@   A�   � �  �D     @      �  �  �       ,         �	(H   (   �� @,   � @@D@�     D        @    �             	      $    �  B� �     0�   � (�  ��  @     �� �L     �P �  � �� ��$P  @"x��Q�B$T   鈀P�AW@�T�� @  ��@�Bh < !�"4B")�� f�&p�Q@h$�(�   0 TB
					  �   P` 0  & �� ��%�   @�  ���  �`" �@ 0   @$  B�   R ��             D      A   0  �  0  �  �@0 �    �   "  � �       ( � A ��n`	�\_           �  �   @      �   @(     �    0
					H           �    @     �     H�   0�    H      @ �    �   �� ����      �� @ @     �          � 0   �       �       D �          �!C@�  �        �*@    ��� +      @   �g� @  	�d   `J  �  8i��   $@� IH�@ �� �   
					! $ �  �   ��,  !�    V(D�  � � � @      � @   @ 	    @* �             �� 0!� 	  �       @         @        �                    �    � P     @         �  D�   �  �    @B              �   �        �   (        �         " f                           @      0    � �  @             �@D  �   �� L  ��$� � �  �" + �3D@ #E��a   @� 0  0 `� HJ ��H bT$     ��h$$ b�    D   �  `@      @      @ ��      �$ @      ! �     @� (    �                         @@    `@   �  �          @  �                           � @ � �_	�^        �                @        � � ��  @          �  A        @     �                  �   @ @ �     @ @   X�                   �   �@              �(            ��     ���    PD!B@   � BT�E      @AH       8  @      	               � �               �   �     A        �  	 	@ @ �!0R     �  �i       ` (  (@                            �        @                 @  b� �       �      
						* ������p`P@0  ��������}rg\PD8,  
						�
						�
						�
						�
						�
						�
						�O
						��
						�
						l�
						V
						?
						,
						
						�������n[H5���q]; ����uaM 7 �������}l[J��� + ����*��	 
						�
						�
						�
						�
						�
						�
						�
						�
						�
						�
						�
						�
						
						u
						k
						a
						W
						M
						C
						9
						/
						%
						
						
							�	�	�	�	�	�	�	�	�	�	�	�	�{ q	g	]	S	I ? 5 + !
							�������������wmcYOE; 1'	�������������}si_UKA7-#�������������yoe[QG=3)�����������{qg]SI?5+!
						���������xmbWtv_secI� + tuple_element_t �''tuple_element �'tuple_element �'tuple_element �'tuple_element �'tuple_element �	'tuple_element �7tuple<_This,_Rest...> �+tuple<_Rest...> ��'tuple_element ��'tuple_element ��7tuple<_This,_Rest...> ��'tuple_element ��
						tuple<> ��'tuple_element ��'tuple_element ��'tuple_element ��'tuple_element ��'tuple_element ��%tuple_size_v ��!tuple_size ��!tuple_size ��!tuple_size ��!tuple_size ��� otrue_type �true_type � true_type ��true_type ��true_type ��true_type ��true_type �
						tv_nsecI�tv_secI�
						tv_nsecI�tv_secI�	type{�	type{�	type{�	type{�	type{�	types	typer�	typep$	typep	typep	typeo�	typek�	typek�	typek�	typek�	typek�	typek�	typek�	typei�	typei�	typef�	typef�	typef�	typef`	typeb�	typeb�
						tv_nsecI�	typeb�	typeb}	typebx	typebg	typebb	type`[	type`=	type]{	type]p	type] ^ type\�	typeY	typeY
							typeY	typeX�	typeX�	typeX�	typeX�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN�	typeN{	typeNs	typeNn	typeN3	typeN - typeN'	typeN"	typeN	typeN	typeN	typeM�	typeLD	typeL<	typeL4	typeL,	typeL%	typeL	typeK�	typeK�	typeK�	typeK�	typeK�	typeK�	typeK-	typeJ�	typeJ�	typeJ�	typeJn	typeJ\	typeJV	typeJK	typeJ9	typeJ3	typeJ,	typeI�	typeI�	typeI�	typeI�	typeI�	typeIw	typeIW	typeIP	typeI	typeI	typeH�	typeH�	typeH�	typeH�	typeH�	typeH�	typeH�	typeH�	typeH�	typeH�	typeH�	typeHz	typeHs	typeG�	typeG{	typeGu	typeGp	typeGi	typeGa	typeG[	typeGW	typeGO	typeGI	typeGE	typeG;	typeG4	typeG 	typeG	typeG	type1�	type1�	type1u	type1[	type!d	type	type	type	type
							type�	type�	type�	type�	type�	type�	type�	type�	type�	typej	typed	typeZ	typeJty ��ty մtyWtyW	%tuple_size_v{� ? tuple_size<_Tuple>::value{�!tuple_size ��!tuple_size ��!tuple_size �!tuple_size �!tuple_size �!tuple_size �!tuple_size | !tuple_size{�!tuple_size{�!tuple_size{�!tuple_size{�!tuple_size{�!tuple_size{� + tuple_element_t{�'tuple_element|'tuple_element |
						'tuple_element{�'tuple_element{�'tuple_element{�'tuple_element{�'tuple_element{�'tuple_element{�'tuple_element{�'tuple_element{�'tuple_element{�'tuple_element{�'tuple_element{�'tuple_element{� - tuple<_Types...> � - tuple<_Types...>{�7tuple<_This,_Rest...> | 7tuple<_This,_Rest...>{� + tuple<_Rest...>{�tuple<>{�tuple ��
						tuplez�	try � ? try�truncl ��truncl%�truncf �Vtruncf$}trunc �trunc ��trunc ��trunc ��trunc �\
						trunc#�
						trunc |
						trunc
						trunc�
						trunc > truename �.
						truenametrue_type �mtrue_type �itrue_type �etrue_type �true_type ֆtrue_type �Qtrue_type �7true_type �true_type �8true_type ǳtrue_type Ǫtrue_type �Qtrue_type �Atrue_type �8true_type � / true_type �)true_type ��true_type ��true_type �    true_type �true_type �
						   3 � �Q��&
						�
						�
						�
						d
						(���IwA 
						�
						�
						R
							@	� | Q���s8	�yL
						���W*���h � �                                                        ; ��	
							    	{_{

							_Other1class  � � � �_oth)��

						};