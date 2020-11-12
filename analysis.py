import pandas as pd
import matplotlib.pyplot as plt 
import seaborn as sns

### read json data
def get_data_as_df():
    df = pd.read_json('sorted_final_data.json')
    return df

### using seaborn and matplot libraries to get age distribution of atheletes
def draw_age_distribution(df):
    sns.distplot(df['age'], hist=True, kde=True, 
        bins=int(180/5), color = 'green',
        hist_kws={'edgecolor':'black'},
        kde_kws={'linewidth': 8},
        label = 'Age')

    plt.rcParams['figure.figsize'] = (15, 10)
    plt.title('Age distribution', size = 15)
    plt.xlabel('Age', size = 15)

    plt.savefig('./static/images/age.png')


### draw the table data and save it as an image
def draw_country_distribution(df):
    sns.distplot(df['country'], hist=True, kde=True, 
        bins=int(180/5), color = 'yellow',
        hist_kws={'edgecolor':'black'},
        kde_kws={'linewidth': 8},
        label = 'Age')

    plt.rcParams['figure.figsize'] = (15, 10)
    plt.title('Country Distribution', size = 15)
    plt.xlabel('Country', size = 15)

    plt.savefig('./static/images/country.png')



### get the winner of the competition
def get_highest_score(df):
    j = df.loc[df['score'].argmax()].to_json()
    return j

def get_lowest_score(df):
    j = df.loc[df['score'].argmin()].to_json()
    return j

if __name__ == "__main__":
    df = get_data_as_df()
    draw_age_distribution(df)
    # draw_country_distribution(df)