#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = NULL;
  if (haystack != NULL && needle != NULL) {
    if (*needle == '\0') result = (char *)haystack;

    while (*haystack) {
      if (*haystack == *needle) {
        const char *start = haystack;
        const char *sub = needle;

        while (*start && *sub && (*start == *sub)) {
          ++start;
          ++sub;
        }

        if (*sub == '\0') result = (char *)haystack;
      }
      ++haystack;
    }
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  const char *last_occurrence = NULL;
  while (*str) {
    if (*str == (char)c) {
      last_occurrence = str;
    }
    str++;
  }
  if (c == '\0') last_occurrence = (char *)str;

  return (char *)last_occurrence;
}

size_t s21_strcspn(const char *str1, const char *str2) {
  int count = 0;
  if (str1 && str2) {
    while (*str1 && !s21_strchr(str2, *str1)) {
      str1++;
      count++;
    }
  }
  return count;
}

void *s21_memchr(const void *s, int c, size_t n) {
  const unsigned char *p = (const unsigned char *)s;
  void *result = NULL;
  for (size_t i = 0; i < n; i++) {
    if (p[i] == (unsigned char)c) {
      result = (void *)(p + i);
    }
  }
  return result;
}

void *s21_memset(void *s, int c, size_t n) {
  unsigned char *p = s;
  for (size_t i = 0; i < n; i++) {
    p[i] = (unsigned char)c;
  }
  return s;
}

char *s21_strchr(const char *s, int c) {
  char *result = NULL;
  while (*s) {
    if (*s == c) {
      result = (char *)s;
    }
    s++;
  }
  if (c == '\0') result = (char *)s;
  return result;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;
  while (n--) {
    *d++ = *s++;
  }
  return dest;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
  char *ptr = dest + s21_strlen(dest);
  while (n-- && *src) {
    *ptr++ = *src++;
  }
  *ptr = '\0';
  return dest;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = NULL;

  while (*str1 && !result) {
    for (const char *s = str2; *s; s++) {
      if (*str1 == *s) {
        result = (char *)str1;
        break;
      }
    }
    str1++;
  }

  return result;
}

size_t s21_strlen(const char *str) {
  size_t result = 0;
  while (*str) {
    result++;
    str++;
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *next_token;
  char *token;

  if (str != NULL) next_token = str;
  if (*next_token == '\0') token = NULL;

  while (*next_token && s21_strchr(delim, *next_token)) {
    next_token++;
  }

  token = next_token;

  if (*next_token == '\0') {
    token = NULL;
  }

  while (*next_token && !s21_strchr(delim, *next_token)) {
    next_token++;
  }

  if (*next_token) {
    *next_token = '\0';
    next_token++;
  }

  return token;
}
// s21_memcmp
int s21_memcmp(const void *str1, const void *str2, size_t n) {
  int result = 0;
  const unsigned char *ptr1 = str1;
  const unsigned char *ptr2 = str2;

  for (size_t i = 0; i < n; i++) {
    if (ptr1[i] != ptr2[i]) {
      if ((int)ptr1[i] - (int)ptr2[i] < 0) {
        result = -1;
      } else
        result = 1;
      break;
    }
  }

  return result;
}
// s21_strncpy
char *s21_strncpy(char *destination, const char *source, size_t num) {
  size_t i = 0;
  while (source[i] != '\0' && i < num) {
    destination[i] = source[i];
    i++;
  }

  destination[i] = '\0';

  return destination;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
#ifdef __linux__
  int res = 0;
  int flag = 1;

  for (size_t i = 0; i < n && flag == 1; i++) {
    if (str1[i] != str2[i]) {
      res = str1[i] - str2[i];
      flag = 0;
    }
  }

  return res;
#endif

#ifdef __APPLE__
  int result = 0;
  const unsigned char *ptr1 = (const unsigned char *)str1;
  const unsigned char *ptr2 = (const unsigned char *)str2;

  for (size_t i = 0; i < n; i++) {
    if (ptr1[i] != ptr2[i]) {
      if ((int)ptr1[i] - (int)ptr2[i] < 0) {
        result = -1;
      } else
        result = 1;
      break;
    }
  }

  return result;
#endif
}

#ifdef __linux__
static const char *s21_error[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};
static const int s21_error_count = sizeof(s21_error) / sizeof(s21_error[0]);
#endif

#ifdef __APPLE__
static const char *s21_error[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"};
static const int s21_error_count = sizeof(s21_error) / sizeof(s21_error[0]);
#endif

char *s21_strerror(int errnum) {
  const char **error_message = s21_error;
  static char *result;
  static char unknown_buf[200];
  if (errnum < 0 || errnum >= s21_error_count) {
#ifdef __APPLE__
    s21_sprintf(unknown_buf, "Unknown error: %d", errnum);
    result = unknown_buf;
#endif

#ifdef __linux__
    s21_sprintf(unknown_buf, "Unknown error %d", errnum);
    result = unknown_buf;
#endif
  } else {
    result = (char *)error_message[errnum];
  }
  return result;
}
//-----------------------------------------------
void *s21_to_upper(const char *str) {
  char *result;
  static char to_upp_str[MAX_LEN];
  s21_strncpy(to_upp_str, str, s21_strlen(str));
  to_upp_str[s21_strlen(str)] = '\0';
  for (size_t i = 0; i < s21_strlen(to_upp_str); i++) {
    if (to_upp_str[i] >= 'a' && to_upp_str[i] <= 'z') {
      to_upp_str[i] -= 32;
    }
    result = to_upp_str;
  }
  return (void *)result;
}

void *s21_to_lower(const char *str) {
  char *result;
  static char to_low_str[MAX_LEN];
  s21_strncpy(to_low_str, str, s21_strlen(str));
  to_low_str[s21_strlen(str)] = '\0';
  for (size_t i = 0; i < s21_strlen(to_low_str); i++) {
    if (to_low_str[i] >= 'A' && to_low_str[i] <= 'Z') {
      to_low_str[i] += 32;
    }
    result = to_low_str;
  }
  return (void *)result;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *new_str = NULL;
  if (src != NULL) {
    int index = (int)start_index;

    if (index >= 0 && start_index <= s21_strlen(src)) {
      static char str1[MAX_LEN];
      str1[0] = '\0';
      s21_strncat(str1, src, start_index);
      s21_strncat(str1, str, s21_strlen(str));
      s21_strncat(str1, src + start_index, s21_strlen(src) - start_index);
      new_str = str1;
    }
  }
  return (void *)new_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_str = NULL;
  if (src != NULL) {
    static char str1[MAX_LEN];
    str1[0] = '\0';
    size_t i = 0, j = s21_strlen(src);
    while (s21_memchr(trim_chars, src[i], s21_strlen(trim_chars)) != NULL) {
      i++;
    }
    while (s21_memchr(trim_chars, src[j - 1], s21_strlen(trim_chars)) != NULL) {
      j--;
    }
    s21_strncat(str1, src + i, j - i);
    new_str = str1;
  }
  return (void *)new_str;
}

//----------------------------------------------------------

void roundToPrecisionInPlace(char *numberStr, int precision) {
  double value = strtod(numberStr, NULL);

  double scale = pow(10.0, precision);
  double rounded = round(value * scale) / scale;

  snprintf(numberStr, s21_strlen(numberStr) + 1, "%.*f", precision, rounded);
}

void uint_to_str(unsigned int value, char *buffer, int base, int uppercase) {
  char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
  char temp[33];
  int i = 0;

  do {
    temp[i++] = digits[value % base];
    value /= base;
  } while (value);

  for (int j = i - 1; j >= 0; j--) *buffer++ = temp[j];

  *buffer = '\0';
}

void float_to_str(double value, char *buffer, int precision) {
  if (precision < 0) precision = 6;

  double scale = pow(10.0, precision);
  value = round(value * scale) / scale;

  long long int_part = (long long)value;
  double frac_part = fabs(value - int_part);

  frac_part = round(frac_part * scale) / scale;

  char int_str[64] = {0};
  snprintf(int_str, sizeof(int_str), "%lld", int_part);
  s21_strncpy(buffer, int_str, s21_strlen(int_str));

  if (precision > 0) {
    s21_strncat(buffer, ".", 2);
    frac_part *= pow(10.0, precision);
    char frac_str[64] = {0};
    snprintf(frac_str, sizeof(frac_str), "%0*lld", precision,
             (long long)(frac_part));
    s21_strncat(buffer, frac_str, s21_strlen(frac_str));
  }
}

void shortest_to_str(double value, char *buffer, int precision,
                     char specifier) {
  char normal[64] = {0}, scientific[64] = {0};

  float_to_str(value, normal, precision - 1);
  scientific_to_str(value, scientific, precision, specifier == 'g' ? 'e' : 'E');

  if (s21_strlen(normal) <= s21_strlen(scientific)) {
    s21_strncpy(buffer, normal, s21_strlen(normal) + 1);
  }

  char *dot = s21_strchr(buffer, '.');
  if (dot) {
    char *end = buffer + s21_strlen(buffer) - 1;
    while (end > dot && *end == '0') {
      *end-- = '\0';
    }
    if (end == dot) *end = '\0';
  }
}

void scientific_to_str(double value, char *buffer, int precision,
                       char specifier) {
  int exponent = 0;
  if (value != 0.0) {
    while (value >= 10.0) {
      value /= 10.0;
      exponent++;
    }
    while (value > 0.0 && value < 1.0) {
      value *= 10.0;
      exponent--;
    }
  }

  float_to_str(value, buffer, precision);
  buffer += s21_strlen(buffer);

  *buffer++ = specifier;
  snprintf(buffer, 6, "%+03d", exponent);
}

int s21_sprintf(char *buffer, const char *format, ...) {
  va_list args;
  va_start(args, format);
  char *buf_ptr = buffer;
  const char *fmt_ptr = format;

  while (*fmt_ptr) {
    if (*fmt_ptr == '%') {
      fmt_ptr++;

      // Флаги
      int left_align = 0, force_sign = 0, space_sign = 0, alt_form = 0,
          zero_pad = 0;
      while (*fmt_ptr == '-' || *fmt_ptr == '+' || *fmt_ptr == ' ' ||
             *fmt_ptr == '#' || *fmt_ptr == '0') {
        if (*fmt_ptr == '-') left_align = 1;
        if (*fmt_ptr == '+') force_sign = 1;
        if (*fmt_ptr == ' ') space_sign = 1;
        if (*fmt_ptr == '#') alt_form = 1;
        if (*fmt_ptr == '0') zero_pad = 1;
        fmt_ptr++;
      }

      // Ширина
      int width = 0;
      if (*fmt_ptr == '*') {
        width = va_arg(args, int);
        fmt_ptr++;
      } else if (*fmt_ptr >= '0' && *fmt_ptr <= '9') {
        while (*fmt_ptr >= '0' && *fmt_ptr <= '9') {
          width = width * 10 + (*fmt_ptr - '0');
          fmt_ptr++;
        }
      }

      // Точность
      int precision = -1;
      if (*fmt_ptr == '.') {
        fmt_ptr++;
        if (*fmt_ptr == '*') {
          precision = va_arg(args, int);
          fmt_ptr++;
        } else {
          precision = 0;
          while (*fmt_ptr >= '0' && *fmt_ptr <= '9') {
            precision = precision * 10 + (*fmt_ptr - '0');
            fmt_ptr++;
          }
        }
      }

      // Длина
      int length_h = 0, length_l = 0, length_L = 0;
      if (*fmt_ptr == 'h') {
        length_h = 1;
        fmt_ptr++;
      } else if (*fmt_ptr == 'l') {
        length_l = 1;
        fmt_ptr++;
      } else if (*fmt_ptr == 'L') {
        length_L = 1;
        fmt_ptr++;
      }

      // Спецификатор формата
      switch (*fmt_ptr) {
        case 'c': {
          char value = (char)va_arg(args, int);
          if (!left_align)
            while (--width > 0) *buf_ptr++ = ' ';
          *buf_ptr++ = value;
          while (--width > 0) *buf_ptr++ = ' ';
          break;
        }

        case 's': {
          char *str = va_arg(args, char *);
          int len = s21_strlen(str);
          if (precision >= 0 && len > precision) len = precision;
          if (!left_align)
            while (width-- > len) *buf_ptr++ = ' ';
          s21_strncpy(buf_ptr, str, len);
          buf_ptr += len;
          while (width-- > len) *buf_ptr++ = ' ';
          break;
        }

        case 'p': {
          void *ptr = va_arg(args, void *);
          char temp[64];
          uint_to_str((unsigned long long)ptr, temp, 16, 0);
          s21_strncpy(buf_ptr, "0x", 2);
          buf_ptr += 2;
          s21_strncpy(buf_ptr, temp, s21_strlen(temp));
          buf_ptr += s21_strlen(temp);
          break;
        }

        case 'n': {
          int *count = va_arg(args, int *);
          *count = buf_ptr - buffer;
          break;
        }

        case 'd':
        case 'i': {
          long long value;
          if (length_l)
            value = va_arg(args, long);
          else if (length_h)
            value = (short)va_arg(args, int);
          else
            value = va_arg(args, int);

          char temp[64];
          char sign[2] = "";

          if (force_sign && value >= 0)
            s21_strncpy(sign, "+", 2);
          else if (space_sign && value >= 0)
            s21_strncpy(sign, " ", 2);
          snprintf(temp, sizeof(temp), "%s%lld", sign, value);

          int len = s21_strlen(temp);
          int padding = width > len ? width - len : 0;

          if (!left_align && !zero_pad)
            while (padding--) *buf_ptr++ = ' ';
          if (zero_pad && !left_align)
            while (padding--) *buf_ptr++ = '0';
          s21_strncpy(buf_ptr, temp, s21_strlen(temp));
          buf_ptr += len;
          if (left_align)
            while (padding--) *buf_ptr++ = ' ';
          break;
        }

        case 'u': {
          unsigned long long value;
          if (length_l)
            value = va_arg(args, unsigned long);
          else if (length_h)
            value = (unsigned short)va_arg(args, unsigned int);
          else
            value = va_arg(args, unsigned int);

          char temp[64];
          snprintf(temp, sizeof(temp), "%llu", value);

          int len = s21_strlen(temp);
          int padding = width > len ? width - len : 0;

          if (!left_align)
            while (padding--) *buf_ptr++ = ' ';
          s21_strncpy(buf_ptr, temp, s21_strlen(temp));
          buf_ptr += len;
          if (left_align)
            while (padding--) *buf_ptr++ = ' ';
          break;
        }

        case 'o': {
          unsigned int value = va_arg(args, unsigned int);
          char temp[64];
          uint_to_str(value, temp, 8, 0);

          if (alt_form && value != 0) *buf_ptr++ = '0';

          int len = s21_strlen(temp);
          int padding = width > len ? width - len : 0;

          if (!left_align)
            while (padding--) *buf_ptr++ = ' ';
          s21_strncpy(buf_ptr, temp, s21_strlen(temp));
          buf_ptr += s21_strlen(temp);
          if (left_align)
            while (padding--) *buf_ptr++ = ' ';
          break;
        }

        case 'x':
        case 'X': {
          unsigned long long value;
          if (length_l)
            value = va_arg(args, unsigned long);
          else if (length_h)
            value = (unsigned short)va_arg(args, unsigned int);
          else
            value = va_arg(args, unsigned int);

          char temp[64];
          snprintf(temp, sizeof(temp), (*fmt_ptr == 'X') ? "%llX" : "%llx",
                   value);
          if (alt_form && value != 0) {
            *buf_ptr++ = '0';
            *buf_ptr++ = 'x';
          }
          int len = s21_strlen(temp);
          int padding = width > len ? width - len : 0;

          if (!left_align)
            while (padding--) *buf_ptr++ = ' ';
          s21_strncpy(buf_ptr, temp, s21_strlen(temp));
          buf_ptr += len;
          if (left_align)
            while (padding--) *buf_ptr++ = ' ';
          break;
        }

        case 'f': {
          long double value;
          if (length_L)
            value = va_arg(args, long double);
          else
            value = va_arg(args, double);

          if (precision < 0) precision = 6;

          char temp[128] = {0};
          float_to_str(value, temp, precision);

          char sign[2] = "";
          if (value >= 0.0) {
            if (force_sign)
              s21_strncpy(sign, "+", 2);
            else if (space_sign)
              s21_strncpy(sign, " ", 2);
          }

          int len = s21_strlen(temp) + s21_strlen(sign);
          int padding = width > len ? width - len : 0;

          if (!left_align && !zero_pad)
            while (padding--) *buf_ptr++ = ' ';
          s21_strncpy(buf_ptr, sign, s21_strlen(sign));
          buf_ptr += s21_strlen(sign);
          if (zero_pad && !left_align)
            while (padding--) *buf_ptr++ = '0';
          s21_strncpy(buf_ptr, temp, s21_strlen(temp));
          buf_ptr += s21_strlen(temp);
          if (left_align)
            while (padding--) *buf_ptr++ = ' ';
          break;
        }

        case 'g':
        case 'G': {
          double value = va_arg(args, double);
          int FLAG = 0;

          if (precision < 0) {
            precision = 6;
            FLAG = 1;
          }

          char temp[128];
          shortest_to_str(value, temp, precision, *fmt_ptr);

          if (alt_form && s21_strchr(temp, '.') == NULL) {
            s21_strncat(temp, ".", s21_strlen(temp));
            s21_strncat(temp, "0", s21_strlen(temp));
            s21_strncat(temp, "0", s21_strlen(temp));
            s21_strncat(temp, "0", s21_strlen(temp));
          }

          if (FLAG) roundToPrecisionInPlace(temp, 3);

          s21_strncpy(buf_ptr, temp, s21_strlen(temp));
          buf_ptr += s21_strlen(temp);
          break;
        }
        case 'e':
        case 'E': {
          long double value;
          if (length_L)
            value = va_arg(args, long double);
          else
            value = va_arg(args, double);
          if (precision < 0) precision = 6;
          char temp[128];
          scientific_to_str(value, temp, precision, *fmt_ptr);
          s21_strncpy(buf_ptr, temp, s21_strlen(temp));
          buf_ptr += s21_strlen(temp);
          break;
        }

        case '%': {
          *buf_ptr++ = '%';
          break;
        }
      }
    } else {
      *buf_ptr++ = *fmt_ptr;
    }
    fmt_ptr++;
  }

  *buf_ptr = '\0';
  va_end(args);
  return buf_ptr - buffer;
}

//----------------------------------------------------------

int s21_sscanf(const char *str, const char *format, ...) {
  int result = 0;
  va_list factor;
  va_start(factor, format);
  int current_char = 0;
  char all_format[] = "*hlLcdieEfgGosuxXpn";
  Format_symb ss_symb;
  int length_format = s21_strlen(format);
  int current_format = 1;
  while (current_format < length_format) {
    if (*format == '%') {
      format++;
      current_format++;
      update_ss_symb(&ss_symb);
      if (current_format == length_format &&
          s21_memchr(all_format, *format, sizeof(all_format)) != NULL) {
        ss_symb.specifier = *format;
      }
      while ((s21_memchr(all_format, *format, sizeof(all_format)) != NULL ||
              (*format >= '0' && *format <= '9')) &&
             current_format != length_format) {
        pars_format(&ss_symb, &format, &current_format);
        if (current_format == length_format) {
          ss_symb.specifier = *format;
        }
      }
      logic_specifier(&ss_symb, &current_char, str, &factor, &result);
    }
    if (*format != '%' && current_format != length_format) {
      format++;
      current_format++;
      current_char++;
    }
  }

  va_end(factor);
  return result;
}

void logic_specifier(Format_symb *ss_format, int *current_char, const char *str,
                     va_list *factor, int *res) {
  switch (ss_format->specifier) {
    case 'c':
      c_flag(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
    case 's':
      s_flag(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
    case 'd':
      d_flag(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
    case 'u':
      u_flag(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
    case 'f':
      f_flag(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
    case 'n':
      n_flag(ss_format, current_char, factor, res);
      (*current_char)++;
      break;
    case 'o':
      o_flag(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
    case 'x':
      x_X_flags(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
    case 'X':
      x_X_flags(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
    case 'p':
      p_flag(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
    case 'i':
      i_flag(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
    case 'e':
      e_flag(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
    case 'E':
      E_flag(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
    case 'g':
      g_flag(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
    case 'G':
      G_flag(ss_format, current_char, str, factor, res);
      update_current_char(current_char, str);
      break;
  }
}

void update_ss_symb(Format_symb *ss_symbols) {
  ss_symbols->width = 0;
  ss_symbols->length = 0;
  ss_symbols->no_reg = 0;
  ss_symbols->specifier = 0;
}

void update_current_char(int *current_char, const char *str) {
  while (str[*current_char] != ' ' && str[*current_char] != '\0') {
    (*current_char)++;
  }
}

void pars_format(Format_symb *ss_format, const char **c, int *current_format) {
  char length_format[] = "hlL";
  if (**c >= '0' && **c <= '9') {
    ss_format->width = ss_format->width * 10 + (**c - '0');
  } else if (**c == '*') {
    ss_format->no_reg = 1;
  } else if (s21_memchr(length_format, **c, sizeof(length_format)) != NULL) {
    ss_format->length = **c;
  } else {
    ss_format->specifier = **c;
  }
  (*current_format)++;
  (*c)++;
}

void c_flag(Format_symb *ss_format, int *current_char, const char *str,
            va_list *factor, int *res) {
  if (ss_format->no_reg == 0) {
    char *symb = va_arg(*factor, char *);
    *symb = str[*current_char];
    (*res)++;
  }
}

void s_flag(Format_symb *ss_format, int *current_char, const char *str,
            va_list *factor, int *res) {
  if (ss_format->no_reg == 0) {
    char *symb = va_arg(*factor, char *);
    int count = 0;
    while (str[*current_char] != ' ' && str[*current_char] != '\0' &&
           (ss_format->width == 0 || count < ss_format->width)) {
      symb[count] = str[*current_char];
      (*current_char)++;
      count++;
    }

    if (count < ss_format->width) {
      while (count != ss_format->width) {
        symb[count] = ' ';
        count++;
      }
    }
    symb[count] = '\0';
    (*res)++;
  }
}

void d_flag(Format_symb *ss_format, int *current_char, const char *str,
            va_list *factor, int *res) {
  if (ss_format->no_reg == 0) {
    void *symb;
    long int num = 0;

    if (ss_format->length == 'h') {
      symb = va_arg(*factor, short int *);
    } else if (ss_format->length == 'l') {
      symb = va_arg(*factor, long int *);
    } else {
      symb = va_arg(*factor, int *);
    }

    int count = 0, sign = 1;
    if (str[*current_char] == '+' || str[*current_char] == '-') {
      if (str[*current_char] == '-') sign = -1;
      (*current_char)++;
    }
    while ((str[*current_char] >= '0' && str[*current_char] <= '9') &&
           (ss_format->width == 0 || count < ss_format->width)) {
      num = num * 10 + (str[*current_char] - '0');
      (*current_char)++;
      count++;
    }

    num *= sign;

    if (count > 0) {
      if (ss_format->length == 'h') {
        *(short int *)symb = (short int)num;
      } else if (ss_format->length == 'l') {
        *(long int *)symb = (long int)num;
      } else {
        *(int *)symb = num;
      }
      (*res)++;
    }
  }
}

void n_flag(Format_symb *ss_format, int *current_char, va_list *factor,
            int *res) {
  if (ss_format->no_reg == 0 && *current_char > 0) {
    int *symb = va_arg(*factor, int *);
    *symb = *current_char;
    (*res)++;
  }
}

void u_flag(Format_symb *ss_format, int *current_char, const char *str,
            va_list *factor, int *res) {
  if (ss_format->no_reg == 0) {
    void *symb;
    unsigned long num = 0;

    if (ss_format->length == 'h') {
      symb = va_arg(*factor, unsigned short *);
    } else if (ss_format->length == 'l') {
      symb = va_arg(*factor, unsigned long *);
    } else {
      symb = va_arg(*factor, unsigned int *);
    }

    int count = 0;
    while ((str[*current_char] >= '0' && str[*current_char] <= '9') &&
           (ss_format->width == 0 || count < ss_format->width)) {
      num = num * 10 + (str[*current_char] - '0');
      (*current_char)++;
      count++;
    }

    if (count > 0) {
      if (ss_format->length == 'h') {
        *(unsigned short *)symb = (unsigned short)num;
      } else if (ss_format->length == 'l') {
        *(unsigned long *)symb = (unsigned long)num;
      } else {
        *(unsigned int *)symb = (unsigned int)num;
      }
      (*res)++;
    }
  }
}

void f_flag(Format_symb *ss_format, int *current_char, const char *str,
            va_list *factor, int *res) {
  if (ss_format->no_reg == 0) {
    void *symb;
    long double num = 0;
    if (ss_format->length == 'L')
      symb = va_arg(*factor, long double *);
    else
      symb = va_arg(*factor, float *);
    int count = 0, sign = 1;
    if (str[*current_char] == '+' || str[*current_char] == '-') {
      if (str[*current_char] == '-') sign = -1;
      (*current_char)++;
    }
    while ((str[*current_char] >= '0' && str[*current_char] <= '9') &&
           (ss_format->width == 0 || count < ss_format->width)) {
      num = num * 10 + (str[*current_char] - '0');
      (*current_char)++;
      count++;
    }
    if (str[*current_char] == '.' &&
        (ss_format->width == 0 || count < ss_format->width)) {
      (*current_char)++;
      double decimal_part = 0, divisor = 10;
      while ((str[*current_char] >= '0' && str[*current_char] <= '9') &&
             (ss_format->width == 0 || count < ss_format->width)) {
        decimal_part += (str[*current_char] - '0') / divisor;
        divisor *= 10;
        (*current_char)++;
        count++;
      }
      num += decimal_part;
    }
    int exponent = 0;
    int exp_sign = 1;
    if (str[*current_char] == 'E' || str[*current_char] == 'e') {
      (*current_char)++;
      if (str[*current_char] == '-') {
        exp_sign = -1;
        (*current_char)++;
      } else if (str[*current_char] == '+')
        (*current_char)++;
    }
    while (str[*current_char] >= '0' && str[*current_char] <= '9') {
      exponent = exponent * 10 + (str[*current_char] - '0');
      (*current_char)++;
    }
    exponent *= exp_sign;
    if (exponent != 0) num *= pow(10, exponent);
    num *= sign;
    if (count > 0) {
      if (ss_format->length == 'L')
        *(long double *)symb = (long double)num;
      else
        *(float *)symb = num;
      (*res)++;
    }
  }
}

void o_flag(Format_symb *ss_format, int *current_char, const char *str,
            va_list *factor, int *res) {
  if (ss_format->no_reg == 0) {
    void *symb;
    long long num = 0;
    if (ss_format->length == 'h')
      symb = va_arg(*factor, short int *);
    else if (ss_format->length == 'l')
      symb = va_arg(*factor, long int *);
    else
      symb = va_arg(*factor, int *);
    int count = 0, sign = 1;
    if (str[*current_char] == '+' || str[*current_char] == '-') {
      if (str[*current_char] == '-') sign = -1;
      (*current_char)++;
    }
    oct_num(ss_format, &num, str, current_char, &count);
    num *= sign;
    if (count > 0) {
      if (ss_format->length == 'h')
        *(short int *)symb = (short int)num;
      else if (ss_format->length == 'l')
        *(long int *)symb = (long int)num;
      else
        *(int *)symb = num;
      (*res)++;
    }
  }
}
void x_X_flags(Format_symb *ss_format, int *current_char, const char *str,
               va_list *factor, int *res) {
  if (ss_format->no_reg == 0) {
    void *symb;
    long long num = 0;
    if (ss_format->length == 'h')
      symb = va_arg(*factor, short int *);
    else if (ss_format->length == 'l')
      symb = va_arg(*factor, long int *);
    else
      symb = va_arg(*factor, int *);
    int count = 0, sign = 1;
    if (str[*current_char] == '+' || str[*current_char] == '-') {
      if (str[*current_char] == '-') sign = -1;
      (*current_char)++;
    }
    if (str[*current_char] == '0' &&
        (str[*current_char + 1] == 'x' || str[*current_char + 1] == 'X'))
      (*current_char) += 2;
    hex_num(ss_format, &num, str, current_char, &count);
    num *= sign;
    if (count > 0) {
      if (ss_format->length == 'h')
        *(short int *)symb = (short int)num;
      else if (ss_format->length == 'l')
        *(long int *)symb = (long int)num;
      else
        *(int *)symb = num;
      (*res)++;
    }
  }
}
void p_flag(Format_symb *ss_format, int *current_char, const char *str,
            va_list *factor, int *res) {
  if (ss_format->no_reg == 0) {
    long long num = 0;

    void **symb = va_arg(*factor, void **);

    if (str[*current_char] == '0' &&
        (str[*current_char + 1] == 'x' || str[*current_char + 1] == 'X')) {
      (*current_char) += 2;
    }
    hex_num(ss_format, &num, str, current_char);

    if (num != 0) {
      *symb = (void *)num;
      (*res)++;
    }
  }
}

void i_flag(Format_symb *ss_format, int *current_char, const char *str,
            va_list *factor, int *res) {
  if (ss_format->no_reg == 0) {
    void *symb;
    long long num = 0;
    if (ss_format->length == 'h')
      symb = va_arg(*factor, short int *);
    else if (ss_format->length == 'l')
      symb = va_arg(*factor, long int *);
    else
      symb = va_arg(*factor, int *);
    int count = 0, sign = 1;
    if (str[*current_char] == '+' || str[*current_char] == '-') {
      if (str[*current_char] == '-') sign = -1;
      (*current_char)++;
    }
    if (str[*current_char] == '0' &&
        (str[*current_char + 1] == 'x' || str[*current_char + 1] == 'X')) {
      (*current_char) += 2;
      hex_num(ss_format, &num, str, current_char, &count);
    } else if (str[*current_char] == '0') {
      (*current_char)++;
      oct_num(ss_format, &num, str, current_char, &count);
    } else {
      while ((str[*current_char] >= '0' && str[*current_char] <= '9') &&
             (ss_format->width == 0 || count < ss_format->width)) {
        num = num * 10 + (str[*current_char] - '0');
        (*current_char)++;
        count++;
      }
    }
    num *= sign;
    if (count > 0) {
      if (ss_format->length == 'h')
        *(short int *)symb = (short int)num;
      else if (ss_format->length == 'l')
        *(long int *)symb = (long int)num;
      else
        *(int *)symb = num;
      (*res)++;
    }
  }
}

void e_flag(Format_symb *ss_format, int *current_char, const char *str,
            va_list *factor, int *res) {
  if (ss_format->no_reg == 0) {
    void *symb;
    long double num = 0;
    if (ss_format->length == 'L')
      symb = va_arg(*factor, long double *);
    else
      symb = va_arg(*factor, double *);
    int count = 0;
    int sign = 1;
    if (str[*current_char] == '+' || str[*current_char] == '-') {
      if (str[*current_char] == '-') sign = -1;
      (*current_char)++;
    }
    while (str[*current_char] >= '0' && str[*current_char] <= '9') {
      num = num * 10 + (str[*current_char] - '0');
      (*current_char)++;
      count++;
    }
    if (str[*current_char] == '.' &&
        (ss_format->width == 0 || count < ss_format->width)) {
      (*current_char)++;
      double decimal_part = 0, divisor = 10;
      while (str[*current_char] >= '0' && str[*current_char] <= '9') {
        decimal_part += (str[*current_char] - '0') / divisor;
        divisor *= 10;
        (*current_char)++;
        count++;
      }
      num += decimal_part;
    }
    int exponent = 0;
    int exp_sign = 1;
    if (str[*current_char] == 'e') {
      (*current_char)++;
      if (str[*current_char] == '-') {
        exp_sign = -1;
        (*current_char)++;
      } else if (str[*current_char] == '+')
        (*current_char)++;
    }
    while (str[*current_char] >= '0' && str[*current_char] <= '9') {
      exponent = exponent * 10 + (str[*current_char] - '0');
      (*current_char)++;
    }
    exponent *= exp_sign;
    if (exponent != 0) {
      num *= pow(10, exponent);
    }
    num *= sign;
    if (count > 0) {
      if (ss_format->length == 'L') {
        *(long double *)symb = (long double)num;
      } else {
        *(double *)symb = num;
      }
      (*res)++;
    }
  }
}

void E_flag(Format_symb *ss_format, int *current_char, const char *str,
            va_list *factor, int *res) {
  if (ss_format->no_reg == 0) {
    void *symb;
    long double num = 0;
    if (ss_format->length == 'L')
      symb = va_arg(*factor, long double *);
    else
      symb = va_arg(*factor, double *);
    int count = 0;
    int sign = 1;
    if (str[*current_char] == '+' || str[*current_char] == '-') {
      if (str[*current_char] == '-') sign = -1;
      (*current_char)++;
      count++;
    }
    while (str[*current_char] >= '0' && str[*current_char] <= '9') {
      num = num * 10 + (str[*current_char] - '0');
      (*current_char)++;
    }
    if (str[*current_char] == '.' &&
        (ss_format->width == 0 || count < ss_format->width)) {
      (*current_char)++;
      double decimal_part = 0, divisor = 10;
      while (str[*current_char] >= '0' && str[*current_char] <= '9') {
        decimal_part += (str[*current_char] - '0') / divisor;
        divisor *= 10;
        (*current_char)++;
        count++;
      }
      num += decimal_part;
    }
    int exponent = 0;
    int exp_sign = 1;
    if (str[*current_char] == 'E') {
      (*current_char)++;
      if (str[*current_char] == '-') {
        exp_sign = -1;
        (*current_char)++;
      } else if (str[*current_char] == '+')
        (*current_char)++;
    }
    while (str[*current_char] >= '0' && str[*current_char] <= '9') {
      exponent = exponent * 10 + (str[*current_char] - '0');
      (*current_char)++;
    }
    exponent *= exp_sign;
    if (exponent != 0) num *= pow(10, exponent);
    num *= sign;
    if (count > 0) {
      if (ss_format->length == 'L')
        *(long double *)symb = (long double)num;
      else
        *(double *)symb = num;
      (*res)++;
    }
  }
}

void g_flag(Format_symb *ss_format, int *current_char, const char *str,
            va_list *factor, int *res) {
  if (ss_format->no_reg == 0) {
    void *symb;
    long double num = 0;
    if (ss_format->length == 'L')
      symb = va_arg(*factor, long double *);
    else
      symb = va_arg(*factor, double *);
    int count = 0;
    int sign = 1;
    if (str[*current_char] == '+' || str[*current_char] == '-') {
      if (str[*current_char] == '-') sign = -1;
      (*current_char)++;
    }
    while (str[*current_char] >= '0' && str[*current_char] <= '9') {
      num = num * 10 + (str[*current_char] - '0');
      (*current_char)++;
      count++;
    }
    if (str[*current_char] == '.' &&
        (ss_format->width == 0 || count < ss_format->width)) {
      (*current_char)++;
      double decimal_part = 0, divisor = 10;
      while (str[*current_char] >= '0' && str[*current_char] <= '9') {
        decimal_part += (str[*current_char] - '0') / divisor;
        divisor *= 10;
        (*current_char)++;
        count++;
      }
      num += decimal_part;
    }
    int exponent = 0;
    int exp_sign = 1;
    if (str[*current_char] == 'e') {
      (*current_char)++;
      if (str[*current_char] == '-') {
        exp_sign = -1;
        (*current_char)++;
      } else if (str[*current_char] == '+')
        (*current_char)++;
      while (str[*current_char] >= '0' && str[*current_char] <= '9') {
        exponent = exponent * 10 + (str[*current_char] - '0');
        (*current_char)++;
      }
      exponent *= exp_sign;
      if (exponent != 0) num *= pow(10, exponent);
    }
    num *= sign;
    if (count > 0) {
      if (ss_format->length == 'L')
        *(long double *)symb = (long double)num;
      else
        *(double *)symb = num;
      (*res)++;
    }
  }
}

void G_flag(Format_symb *ss_format, int *current_char, const char *str,
            va_list *factor, int *res) {
  if (ss_format->no_reg == 0) {
    void *symb;
    long double num = 0;
    if (ss_format->length == 'L')
      symb = va_arg(*factor, long double *);
    else
      symb = va_arg(*factor, double *);
    int count = 0;
    int sign = 1;
    if (str[*current_char] == '+' || str[*current_char] == '-') {
      if (str[*current_char] == '-') sign = -1;
      (*current_char)++;
      count++;
    }
    while (str[*current_char] >= '0' && str[*current_char] <= '9') {
      num = num * 10 + (str[*current_char] - '0');
      (*current_char)++;
    }
    if (str[*current_char] == '.' &&
        (ss_format->width == 0 || count < ss_format->width)) {
      (*current_char)++;
      double decimal_part = 0, divisor = 10;
      while (str[*current_char] >= '0' && str[*current_char] <= '9') {
        decimal_part += (str[*current_char] - '0') / divisor;
        divisor *= 10;
        (*current_char)++;
        count++;
      }
      num += decimal_part;
    }
    int exponent = 0;
    int exp_sign = 1;
    if (str[*current_char] == 'E') {
      (*current_char)++;
      if (str[*current_char] == '-') {
        exp_sign = -1;
        (*current_char)++;
      } else if (str[*current_char] == '+')
        (*current_char)++;
      while (str[*current_char] >= '0' && str[*current_char] <= '9') {
        exponent = exponent * 10 + (str[*current_char] - '0');
        (*current_char)++;
      }
      exponent *= exp_sign;
      if (exponent != 0) num *= pow(10, exponent);
    }
    num *= sign;
    if (count > 0) {
      if (ss_format->length == 'L')
        *(long double *)symb = (long double)num;
      else
        *(double *)symb = num;
      (*res)++;
    }
  }
}

void hex_num(Format_symb *ss_format, long long *num, const char *str,
             int *current_char, ...) {
  va_list factor;
  va_start(factor, current_char);
  int *count = va_arg(factor, int *);
  while (((str[*current_char] >= '0' && str[*current_char] <= '9') ||
          (str[*current_char] >= 'A' && str[*current_char] <= 'F') ||
          (str[*current_char] >= 'a' && str[*current_char] <= 'f')) &&
         (ss_format->width == 0 || *count < ss_format->width)) {
    *num *= 16;
    if (str[*current_char] >= '0' && str[*current_char] <= '9') {
      *num += str[*current_char] - '0';
    } else if (str[*current_char] >= 'A' && str[*current_char] <= 'F') {
      *num += str[*current_char] - 'A' + 10;
    } else {
      *num += str[*current_char] - 'a' + 10;
    }
    (*current_char)++;
    (*count)++;
  }
  va_end(factor);
}

void oct_num(Format_symb *ss_format, long long *num, const char *str,
             int *current_char, ...) {
  va_list factor;
  va_start(factor, current_char);
  int *count = va_arg(factor, int *);
  while ((str[*current_char] >= '0' && str[*current_char] <= '7') &&
         (ss_format->width == 0 || *count < ss_format->width)) {
    *num = *num * 8 + (str[*current_char] - '0');
    (*current_char)++;
    (*count)++;
  }
  va_end(factor);
}
