#ifndef CONFIG_H
#define CONFIG_H

class Config {

	Config() {};

public:
	// ���ׂẴt�@�C���𓯈�̓����ɕύX����
	// �t�@�C�����ƂɕʁX�̓����ɕύX����
	 static bool IsAllFileProp;

	 // �t�H���_�[�̓�����ύX����
	 static bool IsTransformFolderAlso;

	 // �t�H���_�[���̃t�@�C���̓������ύX����
	 static bool IsTransformRecursion;

	 // �쐬����(&C)
	 static bool IsCreateDateTimeTransform;
	 static bool IsCreateDateTimeUseCreate;
	 static bool IsCreateDateTimeUseUpdate;
	 static bool IsCreateDateTimeUseAccess;

	 // �X�V����(&U)
	 static bool IsUpdateDateTimeTransform;
	 static bool IsUpdateDateTimeUseUpdate;
	 static bool IsUpdateDateTimeUseCreate;
	 static bool IsUpdateDateTimeUseAccess;

	 // ��������(&E)
	 static bool IsAccessDateTimeTransform;
	 static bool IsAccessDateTimeUseAccess;
	 static bool IsAccessDateTimeUseCreate;
	 static bool IsAccessDateTimeUseUpdate;
};

bool Config::IsAllFileProp = true;

bool Config::IsTransformFolderAlso = true;

bool Config::IsTransformRecursion = false;

bool Config::IsCreateDateTimeTransform = true;
bool Config::IsCreateDateTimeUseCreate = true;
bool Config::IsCreateDateTimeUseUpdate = false;
bool Config::IsCreateDateTimeUseAccess = false;

bool Config::IsUpdateDateTimeTransform = true;
bool Config::IsUpdateDateTimeUseUpdate = true;
bool Config::IsUpdateDateTimeUseCreate = false;
bool Config::IsUpdateDateTimeUseAccess = false;

bool Config::IsAccessDateTimeTransform = true;
bool Config::IsAccessDateTimeUseAccess = true;
bool Config::IsAccessDateTimeUseCreate = false;
bool Config::IsAccessDateTimeUseUpdate = false;

#endif // CONFIG_H