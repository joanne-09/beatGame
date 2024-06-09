import firebase_admin
from firebase_admin import credentials, storage
import json
# Use a service account

cred_dict = {
  "type": "service_account",
  "project_id": "scoreboard-11703",
  "private_key_id": "c46f6573ef65c274149a847835763b91fbf39d40",
  "private_key": "-----BEGIN PRIVATE KEY-----\nMIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQDluYk8tUfueEWE\nR13CPS//N8MKgqaj0QLEmbek0ibRl9zPy6Om3uVrRIPxwvuqD9Iu00Ud3LZDOZIH\nQJ6K4xrjfTWDarJ7NU4tp+E5zMzaSvlH4wzgybm8anuAhU2ttu1BG2K2hPdQPHVO\ng7JOaILSt8zundDfAF97g+f8ZkThqb0eg7kZ2yai6j3kaEukovgQbu4RMqUipx2G\nEefwiGklRqwELLOKyX1W7dsSsBWmibM6M4ynI9et+ZfiLu4MIPTqaj4+ch3peV0O\nUngAkNuKztHj3Do/F8t61uw/CFwKUdvDlAw3MYPw32mlJTiMmSGHSUS5QsFQC/tX\nlkSjMvW3AgMBAAECggEAEhSseAeT80bVFd22GUZ5Q3RPQ2xYEvcC6ZgTAQPSBAIY\nt47WwRi0ZDZ0JMWiICxMRdzhXkHTuJkh5LSR0JWiX/r9Xha6QyyatsjgAbgcUXwV\ngF0e/jGdDvbZ5JourHhZgRvXhPe/LWSsyPK1ndU8+A/OWeONn9em1uZhY8IQNCs3\n54HRvLj06JKNbeMUwq0vRhWuzvkG6YP/su+DJhmHdZ2PMzwhH2Ld7UY4NRPHU+oC\n3+lEp9Nt0WcezyqC2xbqMOLAsg5ogeHMiZKMc+a+mme+qkMaTFvOAzQB2nM2bR9D\nssjPooHbAR6RGBYz+rfZPwZXZQ9/vhaYFpiu3HkVyQKBgQDzpAK8AaOD6puOY9s+\nPX9Q2OWHchKd7J6yvlg8oQo9XtGOT5XdX/Cz+8ZCDjZBTVDQYTNIcJ9mS8l5UNs1\nc3mucBhqJxjpdeEEXpccQDRcj//pUyGEIJwmDFDH/c71Oa+ANbphuWG5oPHuMZad\naACxjJE/zXcehDnlkp2VzNgOPwKBgQDxYM8pDnSVRM29BWS+1YLL43DW3EcI6bTQ\nHIY0+Gy2/zEj611KE9oixiyxqR2wEVMVsHAc2gcP4IyR09cXOCBIwy3oqgAEPPQq\nftvKVn+5j3/FFnouW6e5XbcIXWTu7N9coqDTufr1phT16gaXdSuK6PJpt13Y9okP\n7a3s+YMqiQKBgQCSn1FF83aEHNwghNecTUYhUWZQbMXnZE7dIs/XLNMMu9NA4YQ/\nBU3GAu79MbBU/EJ2JQjHv38uAM3uxEonkKbZ43vN5lmHpfkUuBgYWEsqqT5JHE4/\nRaCzBRZYRNYXne+QKMVRqk61d7YgspcBg2VndEC1NOFK7CgrkGBlljEv4QKBgAr4\nzpHcMVpzpTJ5Y0n1ZJul/AQYQTZbgTeQhF02CaML2Iz8buImIt0/ytpMiKfvMaqj\nuYTmODn1iA485eMNTxJfpN+VkqieqK6h05XP9sBVkIZB7k3bJrWbV+2OaT8fD0wj\nrFHTe1/dK8i92Yza657F1fcOObraAgLyV9yUvuyZAoGAK3HTMBg/vIQ9luiDtBnM\nGaSYLLxQX5g940ekKa+ljTEbU5D2CCvtn4VQ9UqPUpl0VojadIPMDKrjP7vwzmI6\nnePcqr+XWaRilgSq6+NdQuuQl24O+dSKOyYuu/pXUAJ0S8Z/5bfhqYpG2MQfHnMK\nfOFP+2jO5HZTOg0rD8bDAWg=\n-----END PRIVATE KEY-----\n",
  "client_email": "firebase-adminsdk-9u7y9@scoreboard-11703.iam.gserviceaccount.com",
  "client_id": "105164235204716860807",
  "auth_uri": "https://accounts.google.com/o/oauth2/auth",
  "token_uri": "https://oauth2.googleapis.com/token",
  "auth_provider_x509_cert_url": "https://www.googleapis.com/oauth2/v1/certs",
  "client_x509_cert_url": "https://www.googleapis.com/robot/v1/metadata/x509/firebase-adminsdk-9u7y9%40scoreboard-11703.iam.gserviceaccount.com",
  "universe_domain": "googleapis.com"
}

cred = credentials.Certificate(cred_dict)

firebase_admin.initialize_app(cred, {
    'storageBucket': 'scoreboard-11703.appspot.com'
})

bucket = storage.bucket()

blob = bucket.blob('scoreboard.txt')

# Open the file in read mode
with open('../Resource/scoreboard.txt', 'rb') as my_file:
    blob.upload_from_file(my_file)


local_file_path = '../Resource/downloaded_scoreboard.txt'

blob.download_to_filename(local_file_path)

print('File downloaded')
