///////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2002 - 2011.
//  Copyright 2011 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt
//
// This work is based on an earlier work:
// "Algorithm 910: A Portable C++ Multiple-Precision System for Special-Function Calculations",
// in ACM TOMS, {VOL 37, ISSUE 4, (February 2011)} (C) ACM, 2011. http://doi.acm.org/10.1145/1916461.1916469

#ifdef _MSC_VER
#define _SCL_SECURE_NO_WARNINGS
#endif

#include <boost/detail/lightweight_test.hpp>
#include <boost/array.hpp>
#include "test.hpp"

#if !defined(TEST_MPF_50) && !defined(TEST_MPF) && !defined(TEST_BACKEND) && !defined(TEST_CPP_DEC_FLOAT) && \
    !defined(TEST_MPFR) && !defined(TEST_MPFR_50) && !defined(TEST_MPFI_50) && !defined(TEST_FLOAT128) &&    \
    !defined(TEST_CPP_BIN_FLOAT)
#define TEST_MPF_50
//#  define TEST_MPF
#define TEST_BACKEND
#define TEST_CPP_DEC_FLOAT
#define TEST_MPFI_50
#define TEST_FLOAT128
#define TEST_CPP_BIN_FLOAT

#ifdef _MSC_VER
#pragma message("CAUTION!!: No backend type specified so testing everything.... this will take some time!!")
#endif
#ifdef __GNUC__
#pragma warning "CAUTION!!: No backend type specified so testing everything.... this will take some time!!"
#endif

#endif

#if defined(TEST_MPF_50)
#include <nil/crypto3/multiprecision/gmp.hpp>
#endif
#if defined(TEST_MPFR_50)
#include <nil/crypto3/multiprecision/mpfr.hpp>
#endif
#if defined(TEST_MPFI_50)
#include <nil/crypto3/multiprecision/mpfi.hpp>
#endif
#ifdef TEST_BACKEND
#include <nil/crypto3/multiprecision/concepts/mp_number_archetypes.hpp>
#endif
#ifdef TEST_CPP_DEC_FLOAT
#include <nil/crypto3/multiprecision/cpp_dec_float.hpp>
#endif
#ifdef TEST_FLOAT128
#include <nil/crypto3/multiprecision/float128.hpp>
#endif
#ifdef TEST_CPP_BIN_FLOAT
#include <nil/crypto3/multiprecision/cpp_bin_float.hpp>
#endif

template<class T>
void test() {
    std::cout << "Testing type: " << typeid(T).name() << std::endl;
    static const boost::array<const char*, 51u> data = {{
        "1."
        "05601911274598447512590381143952412839655905253029178781664646797295627642392664834198240236790418665694318420"
        "53263976225991679105269492268050148624443706785607467750929028856273183654547152707568642275917435773104050171"
        "28458077394931390630307481158609621477187980187222550023754072559228816790398715200717139120768003451766421896"
        "5133028298959753155835975555361514087618679892905973726581183754237665",
        "6."
        "05779176509744960239810393466946892048509279589412265077753665894155880302328307581392220107160990591557998531"
        "88868489737439396141346120898610181630988217093945337280471788812956307352429914669334599644412036010014302812"
        "55570090549006203066648238700838485664553310026620512293045549623425247887894967588812261579545107652124477155"
        "4025667181070733415815608287241160724578541982548132473721865287585003",
        "383."
        "32956577005424506758441449272199796616394738942294350035763341369127219359132618750028176886177362785452836065"
        "73588972009869993736599262024616796537678896317165953035019819015627583654728543736601237117591049083582338935"
        "27169814645036727498291835695505095615791814340884076522134211056933589601960444479481908235672911533970397598"
        "20680087749250557665869797605969680417240900163183563482342795870741",
        "180470."
        "88335034971169904627554690213669106779370247753503772451628313223853228134148123711258586005038324156900626143"
        "04738338277308316418851540976695284329448459866830479918641141132957536754633273119043116661326787117700849392"
        "14166497926465680967899714660643449228736431204467593286384477815049329287459745841360396982206040998168778470"
        "80168890581112550484205291341188894903342677757367415636409890558",
        "6."
        "27814979541895132876192971751427700258260524769556003234957905309469004062097894372129233818308898465786517939"
        "22971071825731424267985994598149826652782605981764572599129753631344305259620294513472869937699509893247230674"
        "85002506654766456326395867202986798129602985567509594758730594963413073611869404060857398156019256993547746212"
        "1110619100122692626135788198431038121227062383110684489973794745342204e8",
        "1."
        "61378311475085211322322671024463457408265436342793174717797061014256003543481932366519797827079570761159096101"
        "95029060790302619201096497489621259308501986256217927638422240968232992503387509534910044087310828806601256416"
        "28213970297576817341593254767125933119462446651783267917469179893016103516988279473907996009458208097272806046"
        "395206212403180775656514566222835047724943633607736647735739948551096e13",
        "3."
        "06512100486509488695311966713424774152266431233506177152689718348818346151389259085187035845064471384366136323"
        "41330640449725016173384960626760387649747643297918807083363913015806893683786389067836005832038060734248371426"
        "88680817555421031775601884610962757254631417249270154434596594040877757051931283786001417787275435866246342393"
        "9942202520475422342889660750666147940146262635303938752019875745307992e18",
        "4."
        "30168936021062158647714344640257355471929568870505370146962315269547133313517913760695066887951593166251544581"
        "15179050297716224800318064110052445970764898870599885508391064218065806885129697936678362276766771902589638957"
        "53716833919048827355575387616263323799046261795589223842440212435312473687947465197742235085664298644659194116"
        "3073842974714357745162365700428610167249762162775568692443158879770006e24",
        "4."
        "46086859296813600010249357918906616555060494871223312224917892771380830925078449334838584683411076136574487830"
        "43064935174812965310544903547535217357996429824403225005261842368679242972243707736489629610256554995236901040"
        "77390296237013098988396029898780800800165165079989226776108930213274903706949745230907438984649314022293171461"
        "8697738906019885122076310868220596765753447232222740129365498326869428e31",
        "3."
        "41813159558168064725693574411003900295360033129819319540917443049744915277436012850174566244872649299710227465"
        "16079644284683284072159616291298593217459064246713801084801182706805865477209408120733740982340972570739267039"
        "63058246887607557470618711564386144993942950373060674346608601011512746470631579176526457207045280081605459065"
        "3675962889901898843712936126341807733200610910325052666512334161414655e39",
        "1."
        "93529462827279081014145302127852497636407769190524801588816591906251667334497709126264426283293489997182437317"
        "16720372493614918444193023235879429151628596659929166256368132445762101099318527619217199876328555966639074943"
        "03248513195744818730879742963301327852160193919379798462926667740594397712731448572837824802330973561570848397"
        "758210619453310032286208701226098998940360395267237151018055781640126e48",
        "8."
        "09644495118900985658414964360164316516923077647027842349017414081353813746684390209864706759411109236144469056"
        "96411023621632714191313583360826598468217983223558130595633054971338824192327248896500337050246640453410159732"
        "18441909691717104407571115686780485101838857637153052094369643991767372045091172546678123534721270084970274262"
        "5663288687644090935756560022610000629006347244369388824818661974220426e57",
        "2."
        "50282570926251745491750089522225691418163836379049816443794738582507368961742165396737335216276072093220194134"
        "20937570273676341726636307131078699799472622998437404149614292337267153201903296102921815263736653035269935857"
        "81615908649659426918708244224428089825839704704574672872907979616798789536861403777028637119153057581469585943"
        "3478185016171380286325273493350193132538052551497175771289873181595171e68",
        "5."
        "71683702137926499674663153128641796628951701926950507890613628395108364181246459680329891490683110189943245174"
        "20345278843446068634292140996241291031113395887832891095928020095581695527354104986223411349657526888924224926"
        "67568203204336327977494797605389581967100327640029775835977970360597050732870606469292348116867675199912407369"
        "7599262277247814864401196929320497117521176016017349797292609303756215e79",
        "9."
        "64872611696700312079558418997293865027081250983947778086151839273421639092840259922432010204359151226988086497"
        "11566042372911206942311277943247994427354130507790526857797833309691667380623792736661655695464087154725768656"
        "50760337805322021206789491468614730155076404533751236147883103499967429683763574434403990673410956090879392156"
        "8633128400104314078575159786136202769893309913175064586488844295321363e91",
        "1."
        "20329776602386082325370051588516683110899862359654632492203777786384899723559748482090350823338223099022371650"
        "42868213438627625544096344578102199846440476859557339736747791529782018329078191477783605471526120466881600981"
        "86989037991787881169155531644884273108521898871057121195697201642464975822660650060319497296603203621421375999"
        "1156778846329137084961334557845326183588274571457361004704490747798678e105",
        "1."
        "10883060812782887544924011308975902624045718132814606056838361396692812184425014219355331706369908661651816645"
        "61596333701204545493730707210930818738817252706131805203538144119244917164949716209095542194899833868499263375"
        "70031393425715560127552692130233211800996665099162487822710826507921949736677021914109805096502300591949504802"
        "2616553249266192057652205987267068584616625670961423579715954410508985e119",
        "7."
        "54998805916259656638680428326753009017992457324185017076467921355120532848351382947969760486916683154424278349"
        "49618514094329533376442442492757936744857569785450769927581802961191319878260712808001736830227501518832554201"
        "81622420730061431071243047053802294895743300482972527306792144363552696567397141204969355200425982017338968164"
        "7135125678701502084190660111860351299407405357314966388044340723077086e133",
        "3."
        "79853635800679762402503301653007069582698268515493717324602209234598228090079184957804121097003783527039828995"
        "61570150646963751463572075768540297484136809462018052149545042828665345287117150392150513078663739946623681053"
        "68505465037259587291440042344663580680646178313958620437868058550744621854406884524675301085056534185211101772"
        "8985713047360191412931479535524815646071456825031827933342626130249175e149",
        "1."
        "41213193415725812702153598487066305427766336757115296875934873462592839607080956014948231124866310237211242356"
        "40943167173029348028743563902367757599140008654691320430919753414890689949599421028277624880392344132646738394"
        "54619563826127968754320850393217292627529421842908681656021339918017949400410916454684489963238517783544294617"
        "4689070525154077366030192931540897742543089509897490703511310531249977e166",
        "3."
        "87903077199979745106643397442602333738810961999331522026625565567797837751065639869118595264132820552586125224"
        "99767709123313205863879946518297779104337686883587019222829967005608205535314284003183828513113021722123872387"
        "03643511351735667644737671559540817955526787194767167909898665166571927934802505871381779687679591584415171910"
        "3197410787508530261619841035613531488383930867055908047961915279983259e183",
        "7."
        "87336053738358403974345232640385984056728299256511658470656683243854307460876333488489056378354287394014396798"
        "96923081980364912472282573695612463537585283007941057172128277340402716645674443632827653710173742423648839359"
        "54777769477857667560464588021983337522794199842632588655843521435502224085456355886408062775865343942991707275"
        "3785194675103766900514602432580639079224631229479607396935864512990879e201",
        "1."
        "18082629950389009425178914579262000630180796953484697627255203778763700057715189542510153384028860976897628950"
        "44056273430051256244413916763438966705458118354189107806216991150264176024521937328179762640422127608560103802"
        "43167214486601321640515719770978848419772005770211878816878981607456020807826043354828388153590907111655389789"
        "3659656781376448427981358955547508806938614921874867135186509274509121e221",
        "1."
        "30858174999878426551305488271689556558384321402452281696918922677077787904987739148331993689161140439661973295"
        "62444577848635313938483757629541576533880917215885485474416704968999200090496252044959849927443732134176975867"
        "86998601131597562586800906537304622471606316897778810386688572047109554738534286863201895191060393683578938746"
        "4412366605713487321530237148912677199033012777178113821791621549557963e241",
        "1."
        "07153081480068991619038813538296440692171211386826580344130515756045616495762614285688880942186204446350132207"
        "05511245290719605273316790249367622122178650529000528086055415007045458486410501636380119413632657994999412652"
        "18843006312847033681740148217258036637407933129512920093624644634783238060635329385822275868747961292718153023"
        "6387227215663399410099251455256898414199913458340065553949424990477448e262",
        "6."
        "48331965100630950223764050595501238429357093260235378484937789053462018029627222607642449009757709351188650397"
        "35904093764776116679888935421171735987167888371792653849212017720136116318927292508358228044947423163304066884"
        "75091973437669111728949960922002370308207819760146543720499389938855072810566961589413895110830251224194598788"
        "696990065693705615156654866578134664648091752361824241438921952031149e283",
        "2."
        "89853913045427682931727097752307679814777215288854083053556195306901194262072695630497568249393971572218777755"
        "31212262059946098575425050827283362457005503261796116156917077778477251551070762614233325253060283603452216492"
        "68153183915464923208092878706633839991585032738161467245610237424895021024826679607245762337007919557432284659"
        "4267768883120374288952014885152055438195794090975578878933873824774214e306",
        "9."
        "57524433627083921372674145950563946532138741951042299439035158875449060589509856903496678820625880407684156184"
        "67576300179061328983586984432582196507026188089413820743600336619502440390216246792909515578785240971073577534"
        "74909093111963153327116805520444674581696153661168724694358406085344894253222472789266720597479112669810243669"
        "89976214521515026692183039600169984107883592297128416659318858313127e329",
        "2."
        "33727345033623693753810095241973508303164720347217597617975362377386704710094235435422515724882290456995981608"
        "34162677357730620072441755506075897500940629883044875771104686291523502165266242030847074909362622098365719455"
        "33235993874613862916130471738526530998089807948995995515764456623244080513770107131149565333060607161133194124"
        "6434767948905863368638163788562679785940566685500460815077065003612487e354",
        "4."
        "21558791269371992409699094485991868684847178872987296051500332991235349928573329181681352308437386959256983838"
        "15575417820480732378749635394939513838137876524333991937836847074991505476867647762082587225838063325020413513"
        "07712832158143942900148597775176579801110109207261305368742298335214046856917156477394123225605706416114234166"
        "1775359191159220450305300322654184921617310753474842253496677498824723e379",
        "5."
        "61818116133757012489702243782567404946920662424376026524697405127382975992354145939996168919451561868277363261"
        "84687322137498447792007445397397290336810468925670064733464757082986791232916898141597610692740388799796632396"
        "70814902724343685975252680511277879064509655577022780987369558996980567860110615755638697422164766959082771235"
        "3133603091803570183764883405340587430017053183637835511899658145649708e405",
        "5."
        "53251106928220535092383018707346612727458446719546860788676375087729439299366382143215888575356349523813139437"
        "38654286540526043262643301046462576597601613866207167167036316086433126132458046255118139642751094515137365585"
        "14977338129201153666764317441936156609643185133981728847167450887861106642311329612564652645663234240748195490"
        "808151911497393974690166034839217817023634217121406163178148652748479e432",
        "4."
        "02566663067613312406532171367315316230170176957139429170278517627053463573307885864114313789720099805323107576"
        "89380174461664677676028378924382554201434975574729861177781849023768222381429947872325368088023224591306630434"
        "88752921545958076086307590768624852116859030963646844864851375289385176731569346963898087464845711433555720211"
        "5472595647478331668869318302753802858726588719006447471192697846325955e460",
        "2."
        "16442373466816634246017817691597979198342453652307355890587969859747455944859888559714139368208719357146022376"
        "43458356241187573307428309041919648027960168541647193436225977495680484218384107820095589356463058222584008532"
        "49706917999367853343113123362931285077152897044363460429014314907920951386813058571300608073348849116032114573"
        "5562062411305931183571279530201672366980412430529846635995189699318073e489",
        "8."
        "59875809811959836620472472169360664857317603153715063860770566914095798560147630326195395399352997161104116887"
        "93466397984311640631361934500807639285587334983206556915704635831992012926186843826981296831658998834850783404"
        "71305082909375312618955662509599462160530004719996233209885723635980168115741960667641219878309281636433604730"
        "6243999363335004760439115355072350465422891365411868472688286678516314e518",
        "2."
        "52416731631871272761346107169547241622702902287736417344208646182452119260176248298406858601305792577721263986"
        "22324109858115624706486522844752512951837805396709793171502497523431473021570806024043139443284538862368635312"
        "79953910826408402803273129548728218861682026168963492642713506088794279763514769384995005867275345857647649173"
        "3064455826768562371858057444914175251596852571637211466017938478085247e549",
        "5."
        "47506791182338766132594205708195704492779627444127804280501483514467832109262303414703151880706323497607310257"
        "42570791702834581720467527197241529413168425211960698044258765079274184234095237392617266811206620971599430494"
        "01039490818332686968135012747332468921142470970507219403290422458185430415836291605355383658657658638112408092"
        "789126678938878667507151950931633694006471359998448912249374833586727e580",
        "8."
        "77505496899502567766394687245741586296033200143902756810286745508263570801364223994762134327913766562227638006"
        "28593282303459051561266270006921840049305819767639184391149913915312831894296821356222752594264134130151457242"
        "71353924842188383735344218172453070693322015850724076032518206800155329494926859617841863416432387497193799707"
        "2367419479635154591248667559627811893588163238012665671798461211917208e612",
        "1."
        "03920001583377732737511565764160246646536796899738563734563048433393029779232542383764970440277281580589033023"
        "90909588333829463843362779584402914847447592731182614369968957680281500946805571235013941407979569788567794900"
        "81025715443359295816754518668713781010184800010733507448605095938797451641465463887974096617578601649279784516"
        "9374594168995878543584318334800124941205910589727264397237600733483158e646",
        "9."
        "09363267536367272405745466788391706650191691109438788949330932115559769957014680414493273700736818986906384661"
        "36204694745206283652338526673125958055131610409923286526192661778126811265116493171283319361595267283588121098"
        "34970395192966928196667559689026648386421759155570755276556575684270105614429007586789352037941952177591304796"
        "4393758374891516340929062076304350159966063972713118995033247759001609e679",
        "5."
        "87982816369304899641620094290092578679067925080588016270421219535999129512653159337234401858255190801029880568"
        "36911095299854840387008575164090793635997912930561430335216151607097220208013034399895832350235280120270626904"
        "35619693516670177376868031106326438089133102151451875783922081850690599784722878343901525276805516616594158203"
        "0353226255576433910936297965207260585437762430381969160714956727596198e714",
        "2."
        "80918812929111084043459758968155589584778352607377945794172845124134733889680575870885550412662974868419236287"
        "02282019643659456724373332519583025947015025975126598748630623031951723754960589046233996595466021913942587558"
        "32666059306319790528857335355910688464528553149762694037980050047428244692923791456853466586870374273171363234"
        "9090897884403966643055728471509474896855575286123275564417626861566706e750",
        "9."
        "91712937259767113206767386673924623817974241723106406296023286672533757528193859721207369716800015502715814816"
        "58616174000808376999687855051075798318036855160548374473251503888674887541706772280965242243924102322062382639"
        "33144338637103531441623303187445874039234973380151391274490746625993568552049954630793219419614845431626975962"
        "881182662815760423226111647056071831411664335144052772436215105801395e786",
        "2."
        "58690271635431111218786799870816477151878728266773984750967386405836598000689673795513763221703475374549181906"
        "03891312949716382621902484616361664158953484778255247083652726854621059785392022847887382779010079407502679229"
        "02108532067590310957376933127741337227236321889639796566258135788673969137620431690897408182198043217806539422"
        "8926767529685562155837452626029223937027004015040825450642409597700449e824",
        "4."
        "98612519312070809237856867988817891938138796108426752053612101558947746863287108939065436824470292069289349675"
        "25495260314937837003448878215156341411477636831113484416124080974502217578408248150338565305116223944900839866"
        "52862296035272393854871331942579845334540299214607886805326360623407444302415524345062363472091243884102296990"
        "9473424559262711669905282193529250216454066716533180418518228387188393e862",
        "7."
        "10125690143390682411017512339532342165228402803424065209092882320127995478719607237198365163595481988427495369"
        "61644100550279020276709043358260853581760590386456213180291689322352732545965831405519844109680619067101311180"
        "95939933992270659609852696914898117351986513950866563131731042417837883337060592244909474551081261856381353734"
        "7841030916512147874232760564378443782164868016244561788356251308121716e901",
        "7."
        "47302153604866421354317547470748853778401956835830182548925022450119737120842211168133644234928020807997681745"
        "34590613188275471080608467087354983850284805514875889145266688973752185071777341375422809910165581997555433091"
        "93995940656983118345987234477870709809494119348906153216024977585642656969612719345333954837167922967627266308"
        "4782830276508737129506676031759345288056484158647796152349867328841634e941",
        "5."
        "81093753642091122275796546587309770308694543886070769036394659922966168320029641380009476688371405433259082226"
        "88655359602408511410663722770167244801973012245657865182739637159804595049180263175014778215232564251739259624"
        "75958995367766135610455483155107326366818828386112352168844513216414776232111159702852313009386415399997437679"
        "0494383016372210442340324038686843345053322425194077414241243050491297e982",
        "3."
        "33875955701899627718146291382268063073604182131575843695486667154496711979350813988644889979275310892951143249"
        "90139844785908367473984008445446585047577469632514214867193740710854025084590094114280015734566576140393088979"
        "74248089795695503252715585184045590075516256377611426621077579137632219122829576817840535643871040623177297887"
        "37215450574233690655931888608424916152893688106181220341997128198692e1024",
        "1."
        "41746728778233347096101173197688307390807344073539051456326120888249557201987349966042612500192919558836203335"
        "45750761619015467840567122066622229379056280064206319780047687015558007624774062399477328822231085767309831266"
        "03261605306585873937381865168712809333564038851339619111853718128033443029243918873752436226978927230890572381"
        "2818882228503013875816702686587035844437102478263525616196832018321602e1067",
        "4."
        "44661890167910915168017238808125335284385970805494109112356556113820105031457892861587455557714835779436627687"
        "73465284793798720178177605712848440200402906836390133865748188969184005230383247111166918721449908133920663776"
        "95278668383703818043626473893735410115386717180431576947105030318212926944229235438803729812517794121792684580"
        "3005587166270803697433886463469168814941555804311717400657004050157245e1110",
    }};

    T eg = static_cast<T>(
        "5."
        "77215664901532860606512090082402431042159335939923598805767234884867726777664670936947063291746749514631447249"
        "80708248096050401448654283622417399764492353625350033374293733773767394279259525824709491600873520394816567085"
        "3233151776611528621199501507984793745085705740029921354786146694029604325421519e-1");

    unsigned max_err = 0;
    for (unsigned k = 0; k < data.size(); k++) {
        const T x = eg + k;
        T val = boost::multiprecision::cosh(x * x);
        T e = relative_error(val, T(data[k]));
        unsigned err = e.template convert_to<unsigned>();
        if (err > max_err) {
            std::cout << x * x << std::endl;
            max_err = err;
        }
        val = boost::multiprecision::cosh(-x * x);
        e = relative_error(val, T(data[k]));
        err = e.template convert_to<unsigned>();
        if (err > max_err) {
            std::cout << x * x << std::endl;
            max_err = err;
        }
    }
    std::cout << "Max error was: " << max_err << std::endl;
    BOOST_TEST(max_err < 2000);
}

int main() {
#ifdef TEST_BACKEND
    test<
        boost::multiprecision::number<boost::multiprecision::concepts::number_backend_float_architype>>();
#endif
#ifdef TEST_MPF_50
    test<boost::multiprecision::mpf_float_50>();
    test<boost::multiprecision::mpf_float_100>();
#endif
#ifdef TEST_MPFR_50
    test<boost::multiprecision::mpfr_float_50>();
    test<boost::multiprecision::mpfr_float_100>();
#endif
#ifdef TEST_MPFI_50
    test<boost::multiprecision::mpfi_float_50>();
    test<boost::multiprecision::mpfi_float_100>();
#endif
#ifdef TEST_CPP_DEC_FLOAT
    test<boost::multiprecision::cpp_dec_float_50>();
    test<boost::multiprecision::cpp_dec_float_100>();
#ifndef SLOW_COMPLER
    // Some "peculiar" digit counts which stress our code:
    test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<65>>>();
    test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<64>>>();
    test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<63>>>();
    test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<62>>>();
    test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<61, long long>>>();
    test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<60, long long>>>();
    test<boost::multiprecision::number<
        boost::multiprecision::cpp_dec_float<59, long long, std::allocator<char>>>>();
    test<boost::multiprecision::number<
        boost::multiprecision::cpp_dec_float<58, long long, std::allocator<char>>>>();
#endif
#endif
#ifdef TEST_FLOAT128
    test<boost::multiprecision::float128>();
#endif
#ifdef TEST_CPP_BIN_FLOAT
    test<boost::multiprecision::cpp_bin_float_50>();
    test<boost::multiprecision::number<boost::multiprecision::cpp_bin_float<
        35, boost::multiprecision::digit_base_10, std::allocator<char>, boost::long_long_type>>>();
#endif
    return boost::report_errors();
}
