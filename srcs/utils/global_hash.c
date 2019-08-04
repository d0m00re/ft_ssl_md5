#include "ft_sha256.h"
#include "ft_md5.h"
#include "ft_utils.h"

const t_hash_ref g_hash[] =	{{md5_get, "MD5 ("}, {sha256_get, "SHA256 ("}};
