#!/bin/sh

# Display usage
cpack_usage()
{
  cat <<EOF
Usage: $0 [options]
Options: [defaults in brackets after descriptions]
  --help            print this message
  --version         print cmake installer version
  --prefix=dir      directory in which to install
  --include-subdir  include the Tutorial-1.0-Linux subdirectory
  --exclude-subdir  exclude the Tutorial-1.0-Linux subdirectory
  --skip-license    accept license
EOF
  exit 1
}

cpack_echo_exit()
{
  echo $1
  exit 1
}

# Display version
cpack_version()
{
  echo "Tutorial Installer Version: 1.0, Copyright (c) Humanity"
}

# Helper function to fix windows paths.
cpack_fix_slashes ()
{
  echo "$1" | sed 's/\\/\//g'
}

interactive=TRUE
cpack_skip_license=FALSE
cpack_include_subdir=""
for a in "$@"; do
  if echo $a | grep "^--prefix=" > /dev/null 2> /dev/null; then
    cpack_prefix_dir=`echo $a | sed "s/^--prefix=//"`
    cpack_prefix_dir=`cpack_fix_slashes "${cpack_prefix_dir}"`
  fi
  if echo $a | grep "^--help" > /dev/null 2> /dev/null; then
    cpack_usage
  fi
  if echo $a | grep "^--version" > /dev/null 2> /dev/null; then
    cpack_version
    exit 2
  fi
  if echo $a | grep "^--include-subdir" > /dev/null 2> /dev/null; then
    cpack_include_subdir=TRUE
  fi
  if echo $a | grep "^--exclude-subdir" > /dev/null 2> /dev/null; then
    cpack_include_subdir=FALSE
  fi
  if echo $a | grep "^--skip-license" > /dev/null 2> /dev/null; then
    cpack_skip_license=TRUE
  fi
done

if [ "x${cpack_include_subdir}x" != "xx" -o "x${cpack_skip_license}x" = "xTRUEx" ]
then
  interactive=FALSE
fi

cpack_version
echo "This is a self-extracting archive."
toplevel="`pwd`"
if [ "x${cpack_prefix_dir}x" != "xx" ]
then
  toplevel="${cpack_prefix_dir}"
fi

echo "The archive will be extracted to: ${toplevel}"

if [ "x${interactive}x" = "xTRUEx" ]
then
  echo ""
  echo "If you want to stop extracting, please press <ctrl-C>."

  if [ "x${cpack_skip_license}x" != "xTRUEx" ]
  then
    more << '____cpack__here_doc____'
This is the open source License.txt file introduced in
CMake/Tutorial/Step7...

____cpack__here_doc____
    echo
    while true
      do
        echo "Do you accept the license? [yn]: "
        read line leftover
        case ${line} in
          y* | Y*)
            cpack_license_accepted=TRUE
            break;;
          n* | N* | q* | Q* | e* | E*)
            echo "License not accepted. Exiting ..."
            exit 1;;
        esac
      done
  fi

  if [ "x${cpack_include_subdir}x" = "xx" ]
  then
    echo "By default the Tutorial will be installed in:"
    echo "  \"${toplevel}/Tutorial-1.0-Linux\""
    echo "Do you want to include the subdirectory Tutorial-1.0-Linux?"
    echo "Saying no will install in: \"${toplevel}\" [Yn]: "
    read line leftover
    cpack_include_subdir=TRUE
    case ${line} in
      n* | N*)
        cpack_include_subdir=FALSE
    esac
  fi
fi

if [ "x${cpack_include_subdir}x" = "xTRUEx" ]
then
  toplevel="${toplevel}/Tutorial-1.0-Linux"
  mkdir -p "${toplevel}"
fi
echo
echo "Using target directory: ${toplevel}"
echo "Extracting, please wait..."
echo ""

# take the archive portion of this file and pipe it to tar
# the NUMERIC parameter in this command should be one more
# than the number of lines in this header file
# there are tails which don't understand the "-n" argument, e.g. on SunOS
# OTOH there are tails which complain when not using the "-n" argument (e.g. GNU)
# so at first try to tail some file to see if tail fails if used with "-n"
# if so, don't use "-n"
use_new_tail_syntax="-n"
tail $use_new_tail_syntax +1 "$0" > /dev/null 2> /dev/null || use_new_tail_syntax=""

extractor="pax -r"
command -v pax > /dev/null 2> /dev/null || extractor="tar xf -"

tail $use_new_tail_syntax +152 "$0" | gunzip | (cd "${toplevel}" && ${extractor}) || cpack_echo_exit "Problem unpacking the Tutorial-1.0-Linux"

echo "Unpacking finished successfully"

exit 0
#-----------------------------------------------------------
#      Start of TAR.GZ file
#-----------------------------------------------------------;
� DQ_ �]t[G�I��<�H��N�*�4iY�;iIkǖ#�v��Q�Wne���V�\�*u���R*�[�6�G�B`av�'p8�4����Cۜ�i!n�Ł6���;s5wtoҖ4���������?�{5��Ӿh�������54�y �7��a����1mCM�竩���5�D<��l�0�SZ(	��b�ȩ�R�P<�&m�Y=���I���Ik�d4{��8u����j���74�x0��@<�7K!1����]��V��a�.r5AʷD�>ђ��H6�E��br)�H���A�9.5����g�_H̱C��NQ���cR���h9��Rs,��y.şs�c1���:���d��c����9Y�,߁M��i���E�߷.Ǽ�Z~���"�|��G��!�����xsw����e�i�y�WǢ}�uձȺX4�Y7��~]}�7���P��}Lm��K����Ϯ{�={���9-�T_���71��0~V��'�~Cn�0,߷��T�K���x�����b�k�O�������3h�?`#�"�&}:m�ˆ��6�Gl�����6��=x�M��6�?d�ﰑ�j��Z~�M�+��%dil��J>!e`(W���)
Q�z:���T�)MM�t4�q�'�S�4딛�v'b�@�x�ҧP[8����[�S�X[�[��Ã���%CQ-�.�j�B�hXI���j�Qz|J��^�Yk�EL&�T��X4����!5�u^�%i����5� ��XG�
4�����ZE�!�H)�W�k�G5��^��֮�D���Q��d*5�]�N�Q�f��ׯ�z���)�j{mm�Z�M`�W��k��p"���� ���W����JK���G�.5-#)|��]�Ec
�0.@���ԑ(HT�d2�Pb�pH�&�,�?�����*fcr(��SZ$�f���HOa`EʏTXǷ47+�^i޾�is���֒-�m���N|���uR��	�T��_NX۝�^(���T������⪯�9�{��M9s�F��v-B�i�}�"�e������7�1�i�?P��c�����7���N�=g�}�,-�/�b���Ϗ.@�+��/����-�$<�L�'%|Q�����n����5z��B�i��q�Î
x��O�����>#��
���W	�������\V
8_G�[�|�b�%$�́�#�N_%�n�	��}�A�K�Q�xP�
x��/���X�o�2�r�
�%�W����|��O�y�
������)8�|ip���jXv�=�9�G���*=Lӳ�8{�/�o�%���� &��B��H�9{��OU�_��S��.��
�=@�G��W��$���4.����/�q��K��#����0�?�4.���Q�A�q������%s����E��Y�߅4.��J�F���JJ'��%q�P���ƥpv�d6����m[���̳��_�u����[A��x���1��$���wy	���_�vwc=�����;�zS/���d/6�a�ݔ=�\}2����5�C����'�e `=P�=�_qIK.?�wS��ҵ���M?����/���ئG���� ̈́�n��ہ�q��~o�%�/����g�o�7; �� �F�`f�ǂ��D$8Vt�**;0���1G�_Ez,0�1��Ϡ��*h7��Gː��� �� :��2,���Bai���y�{�:Bf~<���4�Me�������2>�`��7��J&������ZC� �C�Ǵ�#�	dEY�S0-J��C�T0�=L�rS��M �?X�N`��̸u.*o�.� 0ŧf~�̱?��V���'�_�љQ���q�b��'���v�n/�1����x��8�1	�YL;K�ynM0s�����s� �u�����g�Q��n���a����̞W2���=�8�5w��fa���
aO܏��˷��#��1����; qB���Ml��O�غՐ�왇�5���<�3��\0sd^���\�d�5mM��9<!
����*QV�rf3G踞��.G>��t�̅X�X����L%S�Ŋ%�yڔ��t@����`�w0�1)Mh�'P��,6H�Q�a?td���'��������������k�v�ПP����hK�ևN��3���!���������/VT�Q�c��=��f?\��V�f*����t��Z?IG��X�J�>T.}�|}dP��9i���Q���G�8<|X�t������tr>�v�bs쩲�Vi`;��(�B�
L�l�~��:->~��||����?8aTv�T�������]MK+r�Ҏ�G|t��*�&��\�����fj��W�z�Ŋg�o9D;[��wR��A3t���gt�L�˟Y�uf��*8A��l>,s˸Q�5�����,<�m��u����&f��y:1YE'�W�I4�������������tC[�GM�m���z�2����E �n_�*~C�<�G(�Ы.����}Ԟy�=�̯��˞	�v7�,�����֦[�nm�Ѥ��,��]b|�B!B!B!
�MR���AM�����xIo*4�^�!�xz�OM��AՓ�#J��d"�y��MyrrzS�G.ϕ<Z�3�Ɔ=��x��{���<;C���!͉�����$�Y�T.����l|�#���c�8.p]�_
��|���g�\6;	��Y|���}6{�G!�����t���� ĸc���>��x?��^�f�\})|�� �b<��ϣ�A|�m�=M��.��t\���t¡�h�0�Qê����������2��������ڊEw��%ל��+�q0��tE����^gsY��J�!vw�ӒK>�ۋ	������u=�	vm�C��������Ð�g�G����r�h2M����E �H�ӯ��Q�/���C�
�+�������I���k3շ�H�A�w!}��ޙ��}���x�CHw�i����{�O@��%k�h/�<��C~�[�+p��W��
�{Ƌ���n)��[,�0Z���1^�����T�js�gsy������������٬�+?���~�E�9��u�#��tФ��7w�{�b�B(�B(�B(�B(�B�{
ܾ���p�n��mS>+��>"�S�=F�!�(�ۄ�c�pnwt�������D���iy�d6Aif4Ŀ\�n�c�ܶ�BFs�^�h���Ej�#n���U��.�6H�Ƥt��\`�{���68��?g��p֓��d�YFs���C&���V��]����he�,�g�N�����3,~�ŏ��G,��_fq1���m�q��]ک��5�O^��'_�������ȟپi��}��c���������j|�-O�x����jg�,f�K�R�47_�Y�ek�j����_̶�N+�i��q��ċ��c��Ƽ1����2�%�84���5��ya��ǌ/2��b����3^n�?f���X���ė��Z�K�޷Z���_f�of|��|q�s{I3~^�ƄW�IK<g�m����t���2���6�|\y~��E68� ;��n���
�OH�&���n��
ҹ9�7�>��L�G2�� ���/����_A�<�r���^�g�����@�^��q�>��S��hSn�M���g.�������\��B?����V�;����͟�wP����A���8�p��>A��ϋ/��?<�@U�H�4/ָql�ϣ�8Я��̳����k�En=��W9u����6�?��۹���gb��&XǗ8���k[]��{l�#�_
r��3_�g��:��՟����^�����m�,��Ț��"�?Ȍ�w���������"����p���Of�F�j�>���s/o+���f�ޭ��K�D���snk�?t�rd=�19�a�-����rڊ����~T~��n����~G_������g���?;����f�������z~�]b-��Zχm���ou�x�"S�:����J�ׇ�Rk�$�]Oh�7LE<� ��RZ��s�W�6����*"	e ��Ŕ��H��Pz��C�1US#�QiɁ5Q%�L�v)j\K�"��А�D�CC� �@)���Uc�����uj�o��a��hJUxJK�úwP�E�&P�u~��E�
;���^>J(Q"��i_4J�-��67�C�t�Ҧ;����<�`s2���Li�j�(��-赦��20��E���6u�5C��n3@}��b���vz�����%�M��Q�R�HHA�oںQQ�it��Ǻ'Bm�H��@ ��S:[{���z�Jggw��2�S����muo��~�;�S���]�ڶ��H4��Sj��p��X;�ܧ��[R3�a�?S18�S	e��7<�O����z��մ�ޤ����=ݤ�no���<����%�竘��SnW��^NKL��h�S�����|/-�N+>/���S��S�W�tc��ZѸ�$a��+Y(�������S{;�MחJ�
�P�����v+��I�CvN�r��72�J+��k1�G�#W�s*G_�O'�cΔ����V��Aο�����W�K��S*OT�4wh�h4�3��Ά�^�f��7�kH�A������0�����ۗ��"��Y�_!4m0�$�Ȯ8��c-�����yL�iI5BF�4ӰH�^X��/�d��&�� ���$s�u$�k
���e�og]��BC�0dIh�^�.f"����V�_�7�~5~z�m5�{ExpH4�|}=�{4VJ��]$�R~�#����G{�������y��������V����|�����܇w������^������G��v}O�����<���wJ��D�c�4ߧ�����"���M�6���~&��>��~�����������^!�y��'�"$�~���)?�G�q����u6�����<VE�l��}������L���$��'ߗs@��o����>������`��v��))?�7��j�_�Oݟ�O�~vߍ��]*��Kt�F����_g����7��o���W
�_�����Y�x~��=�6~OS������P��&��a���g&Y~��.�D�8tY<?���X�F3I�����_�#pX�G:���ϱu�CI���@�]���x�4 ���&���h��A�_�X!���M�����X���/��x6����6ؚ����w���q������ﯫ[_��_�[_W���l�H"��n�*F���j����A���ۜ��G��p��_��������_SS������j��ݞN�Ob��<�xēR5t�Jy�I"�Q��q� �]�m۶*M�n���O�ж|Cow@鸱��'XXo�:!��ۼ��W��;���?�Bg����C��F��{}}C��ﬄK�J��^X�1_޳τ�����p��-�~�'����8� o�����t���6p���vC����F�����7r3���L�(v3R�q��6C��u-����o�a)��f��5�L�3��Lc��p3�����EB˜�Ū�o�f��:��Ex�"v7�X��3g����l7
�1=��8ǝD~�e��v�n�}K��v�\6��.˽I����7k�-�s8/�r�\��㉓(n��-l�~�ᢧ��tw��[���B��o�4�]�\;p˴��.�ڍ��^bidOOz��������9�q���G�J���[m��6�Ɍ�lٯY������������������-�7`�ܘ.^�:c��lkg�f	���/�|&�C���_�ꁯ9ȷT�������2��W%}xy�����0����,pQ~+�R���I>�?q����b#�z�u��"����Pn��?$�+�����/�����O��]��B�Y���2��z�~��F	���m��ʲ���V.��	7u����K��n������1N����,��O���-��#����je��6"��r�X��2.�k����(_�D���O�OOy�a	�߬W��;���t'�xk�~G�+���_1�o�k����+�	�O����i����)�w�X������&���a��
X��$��v'�{Y����?��-�۝|ϱO�w�f�۝|�ا��ӽp�]�P���� S�� t  